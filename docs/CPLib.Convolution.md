# CPLib.Convolution

Defined in cp-library@0.5.2

## Values

### namespace CPLib.Convolution

#### convolve_i64

Type: `Std::Array Std::I64 -> Std::Array Std::I64 -> Std::Array Std::I64`

2つの整数配列の畳み込みを計算する

結果は、要素数が`|a| + |b| - 1`の配列になります。

制約：
- |a| + |b| - 1 <= 2^24
- 結果が`I64`の範囲でオーバーフローしない

##### Parameters

- `a` : 畳み込まれる配列1
- `b` : 畳み込まれる配列2

#### convolve_zp

Type: `[p : CPLib.ZP::PrimeProvider] Std::Array (CPLib.ZP::ZP p) -> Std::Array (CPLib.ZP::ZP p) -> Std::Array (CPLib.ZP::ZP p)`

2つの配列の畳み込みを計算する

結果は、要素数が`|a| + |b| - 1`の配列になります。

制約：2^c|(p-1)かつ|a| + |b| - 1 <= 2^cなるcが存在する

##### Parameters

- `a` : 畳み込まれる配列1
- `b` : 畳み込まれる配列2

## Types and aliases

## Traits and aliases

## Trait implementations