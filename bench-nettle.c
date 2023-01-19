#include "bench.h"
#include <nettle/sha1.h>
#include <stdint.h>

void benchmark(uint8_t *input, size_t input_len, unsigned int loops) {
	struct sha1_ctx sha1;
	uint8_t md[SHA1_DIGEST_SIZE];

	for (unsigned int i=1; i<=loops; i++) {
		sha1_init(&sha1);
		sha1_update(&sha1, input_len, input);
		sha1_digest(&sha1, SHA1_DIGEST_SIZE, md);
	}

}
