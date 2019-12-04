#include "crypto/hash-ops.h"

void cryptonight_hash(const char* input, char* output, uint32_t len, uint64_t height) {
    const int variant = input[0] >= 1 ? input[0] - 1 : 0;
    cn_slow_hash(input, len, output, variant, 1, height);
}

void cryptonight_fast_hash(const char* input, char* output, uint32_t len) {
    cn_fast_hash(input, len, output);
}
