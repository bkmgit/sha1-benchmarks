#include "bench.h"
#include <gnutls/crypto.h>
#include <stdint.h>

void benchmark(uint8_t *input, size_t input_len, unsigned int loops) {
	gnutls_hash_hd_t sha1;
	int size =  gnutls_hash_get_len(GNUTLS_DIG_SHA1);
	uint8_t md[size];
	gnutls_hash_init(&sha1, GNUTLS_DIG_SHA1);
	for (unsigned int i=1; i<=loops; i++) {
		gnutls_hash(sha1, &input, input_len);
		gnutls_hash_output(sha1, &md);
	}
	gnutls_hash_deinit(sha1, &md);

}
