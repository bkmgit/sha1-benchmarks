#include "bench.h"
#include "walton-sha1.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void benchmark(uint8_t *input, size_t input_len, unsigned int loops) {
	char hashout[20];
	uint8_t b1,b2,b3,b4,b5,b6,b7,b8;
	for (unsigned int i=1; i<=loops; i++) {
		uint32_t state[5] = {0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0};
		sha1_process_x86(state, input, input_len);
		b1 = (uint8_t)(state[0] >> 24);
		b2 = (uint8_t)(state[0] >> 16);
		b3 = (uint8_t)(state[0] >>  8);
		b4 = (uint8_t)(state[0] >>  0);
		b5 = (uint8_t)(state[1] >> 24);
		b6 = (uint8_t)(state[1] >> 16);
		b7 = (uint8_t)(state[1] >>  8);
		b8 = (uint8_t)(state[1] >>  0);
		sprintf(hashout,"%02X%02X%02X%02X%02X%02X%02X%02X",
				b1, b2, b3, b4, b5, b6, b7, b8);
	}

}
