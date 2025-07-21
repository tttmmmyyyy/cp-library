# CPLib.Trait

Defined in cp-library@0.1.0

## Values

### namespace CPLib.Trait::Monoid

#### op

Type: `[a : CPLib.Trait::Monoid] a -> a -> a`

演算

非可換な場合は、`op(lhs, rhs)`という用法をします。
これは`rhs.op(lhs)`と同じなので、ドット演算子を使って`op`を呼び出すと左右が反転することに注意！

#### unit

Type: `[a : CPLib.Trait::Monoid] a`

単位元

## Types and aliases

## Traits and aliases

### namespace CPLib.Trait

#### trait `a : Monoid`

モノイドのトレイト

##### method `unit`

Type: `a`

単位元

##### method `op`

Type: `a -> a -> a`

演算

非可換な場合は、`op(lhs, rhs)`という用法をします。
これは`rhs.op(lhs)`と同じなので、ドット演算子を使って`op`を呼び出すと左右が反転することに注意！

## Trait implementations