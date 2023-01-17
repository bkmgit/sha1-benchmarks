#ifndef _BENCH_H
#define _BENCH_H

#include <stddef.h>
#include <stdint.h>

#define MAXLEN 512
#define LOOPS 5000

void benchmark(uint8_t *input, size_t input_len, unsigned int loops);

#endif
