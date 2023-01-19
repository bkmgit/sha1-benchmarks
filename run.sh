./bench-git > bench-git.log
./bench-openssl > bench-openssl.log
./bench-openssl-evp > bench-openssl-evp.log
./bench-nayuki > bench-nayuki.log
./bench-nayuki-x8664 > bench-nayuki-x8664.log
./bench-reid > bench-reid.log
./bench-nettle > bench-nettle.log
./bench-gnutls > bench-gnutls.log
LD_LIBRARY_PATH=../ipp-crypto-install/lib/intel64/:$LD_LIBRARY_PATH ./bench-ipp-crypto > bench-ipp-crypto.log
# TODO
#./bench-walton > bench-walton.log
