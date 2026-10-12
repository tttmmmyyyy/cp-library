# CPLib.Segtree.Test

Defined in cp-library@0.15.0

## Values

### namespace CPLib.Segtree.Test

#### is_sorted

Type: `Std::String -> Std::Bool`

文字列の文字が昇順に並んでいるか

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

#### test_search

Type: `Random::Random -> Std::IO Random::Random`

fold_all、calc_max_right、calc_min_leftが、文書の条件を満たす値を返すことのテスト

要素数0から20の木で、すべての端について調べる。条件には、単調なもの（文字が昇順に並んでいる）と、単調でないもの（長さを3で割った余りが1でない）を使う。

#### test_set_leaves_index_zero

Type: `Std::IO ()`

`set`が使われない添字0の要素を書き換えないことのテスト

書き換えると、文字列の連結のように`op`を重ねるほど値が大きくなるモノイドでは、`set`のたびに根の値が添字0の要素に連結される。

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