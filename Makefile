BINS:=bench-openssl bench-openssl-evp bench-git bench-nayuki \
      bench-nayuki-x8664 bench-reid bench-nettle bench-gnutls \
      bench-walton bench-ipp-crypto
CFLAGS+=

all: $(BINS)

bench.o: CFLAGS+=-O3 -Wall
bench.o: bench.h

bench-openssl.o: CFLAGS+=-O3 -Wall
bench-openssl.o: bench.h
bench-openssl: LDLIBS+=-lcrypto
bench-openssl: bench.o

bench-openssl-evp.o: CFLAGS+=-O3 -Wall
bench-openssl-evp.o: bench.h
bench-openssl-evp: LDLIBS+=-lcrypto
bench-openssl-evp: bench.o

git-sha1.o: CFLAGS+=-O3 -Wall
git-sha1.o: git-sha1.h
bench-git.o: CFLAGS+=-O3 -Wall
bench-git.o: bench.h
bench-git: bench.o git-sha1.o

nayuki-sha1-fast.o: CFLAGS+=-O1 -fomit-frame-pointer
bench-nayuki.o: CFLAGS+=-O1 -fomit-frame-pointer
bench-nayuki.o: bench.h
bench-nayuki: bench.o nayuki-sha1-fast.o

nayuki-sha1-fast-x8664.o: CFLAGS+=-O1
bench-nayuki-x8664.o: bench.h
bench-nayuki-x8664: bench.o nayuki-sha1-fast-x8664.o

reid-sha1.o: CFLAGS+=-O3 -Wall
reid-sha1.o: reid-sha1.h
bench-reid.o: CFLAGS+=-O3 -Wall
bench-reid.o: bench.h
bench-reid: bench.o reid-sha1.o

bench-nettle.o: CFLAGS+=-O3 -Wall
bench-nettle.o: bench.h
bench-nettle: LDLIBS+=-lnettle
bench-nettle: bench.o

bench-gnutls.o: CFLAGS+=-O3 -Wall
bench-gnutls.o: bench.h
bench-gnutls: LDLIBS+=-lgnutls -lnettle
bench-gnutls: bench.o

walton-sha1.o: CFLAGS+=-msse4.1 -msha
walton-sha1.o: walton-sha1.h
bench-walton.o: CLFAGS+=-msse4.1 -msha
bench-walton.o: bench.h
bench-walton: bench.o walton-sha1.o

# Update path to installation of ipp-crypto
# https://github.com/intel/ipp-crypto
bench-ipp-crypto.o: CFLAGS+=-O3 -Wall -I../ipp-crypto-install/include/
bench-ipp-crypto.o: bench.h
bench-ipp-crypto: LDLIBS+=-L../ipp-crypto-install/lib/intel64/ -lippcp
bench-ipp-crypto: bench.o bench-ipp-crypto.o

clean:
	-rm $(BINS)
	-rm *.o
