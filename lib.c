#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// 読み込みに失敗したことを標準エラーに書いて、プログラムを止める。それまでに書いた標準出力は出力する。
static void cp_lib_fail(const char *what, int c)
{
    fflush(stdout);
    if (c == EOF)
    {
        fprintf(stderr, "CPLib.IO: unexpected end of input while reading %s\n", what);
    }
    else if (isgraph(c))
    {
        fprintf(stderr, "CPLib.IO: unexpected character '%c' while reading %s\n", c, what);
    }
    else
    {
        fprintf(stderr, "CPLib.IO: unexpected byte %d while reading %s\n", c, what);
    }
    abort();
}

static int cp_lib_is_space(int c)
{
    return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\v' || c == '\f';
}

// 空白文字を読み飛ばし、その次の文字を読んで返す。
static int cp_lib_skip_spaces(void)
{
    int c = getchar_unlocked();
    while (cp_lib_is_space(c))
    {
        c = getchar_unlocked();
    }
    return c;
}

// 符号と数字の並びを読み、その絶対値と符号を返す。数字の後の文字は読まずに残す。
//
// 値は 2^64 を法として求める。
static uint64_t cp_lib_read_digits(const char *what, int *negative)
{
    int c = cp_lib_skip_spaces();
    *negative = 0;
    if (c == '-' || c == '+')
    {
        *negative = c == '-';
        c = getchar_unlocked();
    }
    if (c < '0' || '9' < c)
    {
        cp_lib_fail(what, c);
    }
    uint64_t value = 0;
    while ('0' <= c && c <= '9')
    {
        value = value * 10 + (uint64_t)(c - '0');
        c = getchar_unlocked();
    }
    if (c != EOF)
    {
        ungetc(c, stdin);
    }
    return value;
}

int64_t cp_lib_read_i64(void)
{
    int negative;
    uint64_t value = cp_lib_read_digits("an integer", &negative);
    return (int64_t)(negative ? -value : value);
}

uint64_t cp_lib_read_u64(void)
{
    int negative;
    uint64_t value = cp_lib_read_digits("an unsigned integer", &negative);
    return negative ? -value : value;
}

double cp_lib_read_double(void)
{
    double value;
    if (scanf("%lf", &value) != 1)
    {
        int c = getchar_unlocked();
        cp_lib_fail("a floating point number", c);
    }
    return value;
}

uint8_t cp_lib_read_char(void)
{
    int c = cp_lib_skip_spaces();
    if (c == EOF)
    {
        cp_lib_fail("a character", c);
    }
    return (uint8_t)c;
}

// 空白文字を読み飛ばし、字句の最初の文字を返す。
uint8_t cp_lib_read_token_head(void)
{
    int c = cp_lib_skip_spaces();
    if (c == EOF)
    {
        cp_lib_fail("a string", c);
    }
    return (uint8_t)c;
}

// 字句の続きの文字を 1 つ読んで返す。字句が終わっていれば（空白文字か入力の終わりなら）-1 を返し、
// 空白文字は読まずに残す。
int64_t cp_lib_read_token_next(void)
{
    int c = getchar_unlocked();
    if (c == EOF)
    {
        return -1;
    }
    if (cp_lib_is_space(c))
    {
        ungetc(c, stdin);
        return -1;
    }
    return c;
}

int64_t cp_lib_popcount64(uint64_t x)
{
    return __builtin_popcountll(x);
}

int64_t cp_lib_popcount32(uint32_t x)
{
    return __builtin_popcount(x);
}
