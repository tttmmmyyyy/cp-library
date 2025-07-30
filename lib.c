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

uint64_t cp_lib_add_mod_signed(int64_t a, int64_t b, uint64_t mod)
{
    __int128_t sum = (__int128_t)a + b;
    __int128_t r = sum % mod;
    if (r < 0)
    {
        r += mod;
    }
    return (uint64_t)(r);
}

uint64_t cp_lib_sub_mod_signed(int64_t a, int64_t b, uint64_t mod)
{
    __int128_t diff = (__int128_t)a - b;
    __int128_t r = diff % mod;
    if (r < 0)
    {
        r += mod;
    }
    return (uint64_t)(r);
}

uint64_t cp_lib_mul_mod_signed(int64_t a, int64_t b, uint64_t mod)
{
    __int128_t product = (__int128_t)a * b;
    __int128_t r = product % mod;
    if (r < 0)
    {
        r += mod;
    }
    return (uint64_t)(r);
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