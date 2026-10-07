#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>

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

// 可変長引数関数でないscanfラッパー
//
// Fix 1.1.0のFFI_CALLは可変長引数関数をサポートしていないため、このようにラップする必要がある。
void cp_lib_scanf(char *format, void *buf)
{
    scanf(format, buf);
}

int64_t cp_lib_popcount64(uint64_t x)
{
    return __builtin_popcountll(x);
}

int64_t cp_lib_popcount32(uint32_t x)
{
    return __builtin_popcount(x);
}