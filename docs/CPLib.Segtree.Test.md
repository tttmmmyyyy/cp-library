# CPLib.Segtree.Test

Defined in cp-library@0.11.1

## Values

### namespace CPLib.Segtree.Test

#### test

Type: `Std::IO ()`

#### test_one

Type: `Std::IO ()`

1要素のセグメント木のテスト

#### test_random

Type: `Std::Bool -> Random::Random -> Std::IO Random::Random`

ランダムにテストを行う

##### Parameters

- `is_build` : セグメント木をbuildで構築するかどうか。そうでないときはinitで構築する
- `rng` : 乱数生成器

#### test_speed

Type: `Std::IO ()`

#### test_three

Type: `Std::IO ()`

3要素のセグメント木のテスト

#### test_two

Type: `Std::IO ()`

2要素のセグメント木のテスト

### namespace CPLib.Segtree.Test::I64Max

#### make

Type: `Std::I64 -> CPLib.Segtree.Test::I64Max`

### namespace CPLib.Segtree.Test::StrConcat

#### make

Type: `Std::String -> CPLib.Segtree.Test::StrConcat`

## Types and aliases

### namespace CPLib.Segtree.Test

#### I64Max

Defined as: `type I64Max = unbox struct { ...fields... }`

最大値モノイド

##### field `v`

Type: `Std::I64`

#### StrConcat

Defined as: `type StrConcat = unbox struct { ...fields... }`

文字列の結合に関するモノイド

##### field `v`

Type: `Std::String`

## Traits and aliases

## Trait implementations

### impl `CPLib.Segtree.Test::I64Max : CPLib.Trait::Monoid`

### impl `CPLib.Segtree.Test::StrConcat : CPLib.Trait::Monoid`

### impl `CPLib.Segtree.Test::StrConcat : Std::Eq`