# CPLib.Bits

Defined in cp-library@0.9.0

ビット操作に関するユーティリティ

## Values

### namespace CPLib.Bits

#### bit_check

Type: `[a : CPLib.Bits::Bits, a : Std::Eq] Std::I64 -> a -> Std::Bool`

第iビットが立っているかを調べる

##### Parameters

- `i` : ビット位置。0 <= i < (ビット幅）でないときは未定義動作
- `x` : 対象のビット列

#### bit_clear

Type: `[a : CPLib.Bits::Bits, a : Std::Eq] Std::I64 -> a -> a`

第iビットを消す

##### Parameters

- `i` : ビット位置。0 <= i < (ビット幅）でないときは未定義動作
- `x` : 対象のビット列

#### bit_combinations

Type: `Std::I64 -> Std::I64 -> CPLib.Bits::BitCombinationIterator`

高々nビットの数のうち、ちょうどmビットが立っているものを昇順で列挙するイテレータ

##### Parameters

- `n` : ビット数（0 <= n <= 62）
- `m` : 立っているビット数

#### bit_flip

Type: `[a : CPLib.Bits::Bits, a : Std::Eq] Std::I64 -> a -> a`

第iビットを反転する

##### Parameters

- `i` : ビット位置。0 <= i < (ビット幅）でないときは未定義動作
- `x` : 対象のビット列

#### bit_set

Type: `[a : CPLib.Bits::Bits, a : Std::Eq] Std::I64 -> a -> a`

第iビットを立てる

##### Parameters

- `i` : ビット位置。0 <= i < (ビット幅）でないときは未定義動作
- `x` : 対象のビット列

#### bit_subsets

Type: `Std::I64 -> CPLib.Bits::BitSubsetIterator`

ビット列の部分集合を降順で列挙するイテレータ

全体集合から始まり、空集合までを列挙する

##### Parameters

- `set` : 全体集合 (0 <= set)

#### to_string_bits

Type: `[a : CPLib.Bits::Bits, a : Std::Eq] Std::I64 -> a -> Std::String`

ビット列を0と1の文字列として表示する

##### Parameters

- `n` : 下位からnビットのみを表示する。0 <= n < (ビット幅) でないときは未定義動作

### namespace CPLib.Bits::Bits

#### and

Type: `[a : CPLib.Bits::Bits] a -> a -> a`

#### not

Type: `[a : CPLib.Bits::Bits] a -> a`

#### one

Type: `[a : CPLib.Bits::Bits] a`

#### or

Type: `[a : CPLib.Bits::Bits] a -> a -> a`

#### popcount

Type: `[a : CPLib.Bits::Bits] a -> Std::I64`

ビット表現における1の個数を数える

##### Parameters

- `x` : 対象のビット列

#### shl

Type: `[a : CPLib.Bits::Bits] Std::I64 -> a -> a`

#### shr

Type: `[a : CPLib.Bits::Bits] Std::I64 -> a -> a`

#### xor

Type: `[a : CPLib.Bits::Bits] a -> a -> a`

#### zero

Type: `[a : CPLib.Bits::Bits] a`

## Types and aliases

### namespace CPLib.Bits

#### BitCombinationIterator

Defined as: `type BitCombinationIterator = unbox struct { ...fields... }`

##### field `sub`

Type: `Std::I64`

##### field `end`

Type: `Std::I64`

#### BitSubsetIterator

Defined as: `type BitSubsetIterator = unbox struct { ...fields... }`

##### field `sub`

Type: `Std::I64`

##### field `set`

Type: `Std::I64`

## Traits and aliases

### namespace CPLib.Bits

#### trait `a : Bits`

##### method `and`

Type: `a -> a -> a`

##### method `or`

Type: `a -> a -> a`

##### method `xor`

Type: `a -> a -> a`

##### method `not`

Type: `a -> a`

##### method `shl`

Type: `Std::I64 -> a -> a`

##### method `shr`

Type: `Std::I64 -> a -> a`

##### method `zero`

Type: `a`

##### method `one`

Type: `a`

##### method `popcount`

Type: `a -> Std::I64`

ビット表現における1の個数を数える

###### Parameters

- `x` : 対象のビット列

## Trait implementations

### impl `CPLib.Bits::BitCombinationIterator : Std::Iterator`

### impl `CPLib.Bits::BitSubsetIterator : Std::Iterator`

### impl `Std::I16 : CPLib.Bits::Bits`

### impl `Std::I32 : CPLib.Bits::Bits`

### impl `Std::I64 : CPLib.Bits::Bits`

### impl `Std::I8 : CPLib.Bits::Bits`

### impl `Std::U16 : CPLib.Bits::Bits`

### impl `Std::U32 : CPLib.Bits::Bits`

### impl `Std::U64 : CPLib.Bits::Bits`

### impl `Std::U8 : CPLib.Bits::Bits`