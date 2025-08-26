# CPLib.Bits

Defined in cp-library@0.6.3

ビット操作に関するユーティリティ

## Values

### namespace CPLib.Bits

#### bit_check

Type: `Std::I64 -> Std::I64 -> Std::Bool`

第iビットが立っているかを調べる

##### Parameters

- `i` : ビット位置 (0 <= i < 64)
- `x` : 対象のビット列

#### bit_clear

Type: `Std::I64 -> Std::I64 -> Std::I64`

第iビットを消す

##### Parameters

- `i` : ビット位置 (0 <= i < 64)
- `x` : 対象のビット列

#### bit_combinations

Type: `Std::I64 -> Std::I64 -> CPLib.Bits::BitCombinationIterator`

nビットの数のうち、ちょうどmビットが立っているものを昇順で列挙するイテレータ

##### Parameters

- `n` : ビット数（0 <= n <= 62）
- `m` : 立っているビット数

#### bit_flip

Type: `Std::I64 -> Std::I64 -> Std::I64`

第iビットを反転する

##### Parameters

- `i` : ビット位置 (0 <= i < 64)
- `x` : 対象のビット列

#### bit_set

Type: `Std::I64 -> Std::I64 -> Std::I64`

第iビットを立てる

##### Parameters

- `i` : ビット位置 (0 <= i < 64)
- `x` : 対象のビット列

#### bit_subsets

Type: `Std::I64 -> CPLib.Bits::BitSubsetIterator`

ビット列の部分集合を降順で列挙するイテレータ

全体集合から始まり、空集合までを列挙する

##### Parameters

- `set` : 全体集合 (0 <= set)

### namespace CPLib.Bits::ToStringBits

#### to_string_bits

Type: `[a : CPLib.Bits::ToStringBits] Std::I64 -> a -> Std::String`

データをビット列として表示する

##### Parameters

- `n` : 下位からnビットのみを表示する

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

#### trait `a : ToStringBits`

##### method `to_string_bits`

Type: `Std::I64 -> a -> Std::String`

データをビット列として表示する

###### Parameters

- `n` : 下位からnビットのみを表示する

## Trait implementations

### impl `CPLib.Bits::BitCombinationIterator : Std::Iterator`

### impl `CPLib.Bits::BitSubsetIterator : Std::Iterator`

### impl `Std::I64 : CPLib.Bits::ToStringBits`