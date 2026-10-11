# CPLib.DSegtree.Test

Defined in cp-library@0.15.0

## Values

### namespace CPLib.DSegtree.Test

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

## Types and aliases

## Traits and aliases

## Trait implementations