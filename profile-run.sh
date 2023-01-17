valgrind --tool=callgrind ./bench-git > bench-git.log
valgrind --tool=callgrind ./bench-openssl > bench-openssl.log
valgrind --tool=callgrind ./bench-openssl-evp > bench-openssl-evp.log
valgrind --tool=callgrind ./bench-nayuki > bench-nayuki.log
