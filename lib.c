#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>

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

int64_t cp_lib_read_i64()
{
    int64_t value;
    scanf("%" SCNd64, &value);
    return value;
}

uint64_t cp_lib_read_u64()
{
    uint64_t value;
    scanf("%" SCNu64, &value);
    return value;
}

double cp_lib_read_double()
{
    double value;
    scanf("%lf", &value);
    return value;
}

uint8_t cp_lib_read_char()
{
    uint8_t value;
    scanf(" %c", &value);
    return value;
}