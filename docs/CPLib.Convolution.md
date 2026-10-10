# CPLib.Convolution

Defined in cp-library@0.15.0

## Values

### namespace CPLib.Convolution

#### convolve_i64

Type: `Std::Array Std::I64 -> Std::Array Std::I64 -> Std::Array Std::I64`

2つの整数配列の畳み込みを計算する

結果は、要素数が`|a| + |b| - 1`の配列になります。

制約：|a| + |b| - 1 <= 2^24, 結果が`I64`に収まる

計算量：O(n log n)、n = |a| + |b|

##### Parameters

- `a` : 畳み込まれる配列1
- `b` : 畳み込まれる配列2

#### convolve_zp

Type: `[p : CPLib.ZP::PrimeProvider] Std::Array (CPLib.ZP::ZP p) -> Std::Array (CPLib.ZP::ZP p) -> Std::Array (CPLib.ZP::ZP p)`

2つの配列の畳み込みを計算する

結果は、要素数が`|a| + |b| - 1`の配列になります。

制約：2^c | (p-1) かつ |a| + |b| - 1 <= 2^c なる c が存在する

計算量：O(n log n + sqrt(p))、n = |a| + |b|。pが`CPLib.ZP`に定義されている素数ならO(n log n)

##### Parameters

- `a` : 畳み込まれる配列1
- `b` : 畳み込まれる配列2

##### Examples

```fix
let a = [1, 2].map(ZP::make) : Array (ZP P998244353);
let b = [3, 4].map(ZP::make);
// (1 + 2x)(3 + 4x) = 3 + 10x + 8x^2
assert_eq(|_|"", convolve_zp(a, b).map(@value), [3_U32, 10_U32, 8_U32])
```

## Types and aliases

## Traits and aliases

## Trait implementations