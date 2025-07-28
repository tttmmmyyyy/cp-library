#include <stdint.h>

// Fixコンパイラが128bit整数をサポートしていないため、64bit整数のmod nでの乗算及び加算をGCCの128bit整数を使用して実装する。

uint64_t cp_lib_mul_mod(uint64_t a, uint64_t b, uint64_t mod)
{
    __uint128_t product = (__uint128_t)a * b;
    return (uint64_t)(product % mod);
}

uint64_t cp_lib_add_mod(uint64_t a, uint64_t b, uint64_t mod)
{
    __uint128_t sum = (__uint128_t)a + b;
    return (uint64_t)(sum % mod);
}