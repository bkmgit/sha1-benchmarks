#include "bench.h"
#include "reid-sha1.h"
#include <stdint.h>
void benchmark(uint8_t *input, size_t input_len, unsigned int loops) {
	SHA1_CTX sha1;
	unsigned char hashout[20];

	for (unsigned int i=1; i<=loops; i++) {
		SHA1Init(&sha1);
		SHA1Update(&sha1, input, input_len);
		SHA1Final(hashout, &sha1);
	}

}
