#include "bench.h"
#include <openssl/evp.h>
#include <stdint.h>

void benchmark(uint8_t *input, size_t input_len, unsigned int loops) {
        EVP_MD_CTX *mdctx;
	unsigned char md_value[EVP_MAX_MD_SIZE];
	unsigned int md_len;
	mdctx = EVP_MD_CTX_create();
	EVP_MD_CTX_init(mdctx);
        EVP_DigestInit_ex(mdctx, EVP_sha1(), NULL);
	for (unsigned int i=1; i<=loops; i++) {
		//EVP_DigestInit_ex(mdctx, EVP_sha1(), NULL);
		EVP_DigestUpdate(mdctx, input, input_len);
		EVP_DigestFinal_ex(mdctx, md_value, &md_len);
	}
	EVP_MD_CTX_destroy(mdctx);

}
