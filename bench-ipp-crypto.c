#include "bench.h"
#include <ippcp.h>
#include <stdint.h>

void benchmark(uint8_t *input, size_t input_len, unsigned int loops) {
//	SHA_CTX sha1;
//	unsigned char md[SHA_DIGEST_LENGTH];
        /*! Internal function status */
        IppStatus status = ippStsNoErr;
	const int digestSizeBit = IPP_SHA1_DIGEST_BITSIZE;
        const int digestSizeByte = digestSizeBit / 8;
        /* Pointer to the SHA-1 hash method */
        const IppsHashMethod* hashMethod = ippsHashMethod_SHA1();
        /* 1. Create a digest by message */
        /*! Buffer create digest */

	uint8_t md[digestSizeByte];
	for (unsigned int i=1; i<=loops; i++) {
//		SHA1_Init(&sha1);
//		SHA1_Update(&sha1, input, input_len);
//		SHA1_Final(md, &sha1);

           /*! Create digest by message */
           status = ippsHashMessage_rmf(input,
                                        input_len,
                                        md,
                                        hashMethod);

	}

}
