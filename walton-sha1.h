// Public domain
#include <stdint.h>
#include <x86intrin.h>

void sha1_process_x86(uint32_t state[5], const uint8_t *data, uint32_t length);

