# CPLib.Monoid.Test

Defined in cp-library@0.15.0

## Values

### namespace CPLib.Monoid.Test

#### check_lsegtree

Type: `[a : CPLib.Trait::Action, a : CPLib.Trait::Monoid, e : Std::Eq, e : Std::ToString, m : CPLib.Trait::Monoid, CPLib.Trait::Action::Set a = m] Std::String -> (e -> m) -> (m -> e) -> (e -> e -> e) -> e -> (Random::Random -> (Random::Random, e)) -> (Random::Random -> (Random::Random, a, e -> e)) -> Random::Random -> Std::IO Random::Random`

`LSegtree`の`fold`と`fold_all`が、要素ごとに作用を行った配列の素朴な畳み込みと一致することを確かめる

##### Parameters

- `name` : 失敗したときに表示する名前
- `to_m` : 要素の値から葉を作る関数
- `from_m` : モノイドの値から要素の値を読む関数
- `naive_op` : 要素の値どうしの演算
- `naive_unit` : `naive_op`の単位元
- `gen` : 要素の値をランダムに作る関数
- `gen_act` : 作用と、それを1要素に行う関数をランダムに作る関数
- `rng` : 乱数生成器

#### check_segtree

Type: `[e : Std::Eq, e : Std::ToString, m : CPLib.Trait::Monoid] Std::String -> (e -> m) -> (m -> e) -> (e -> e -> e) -> e -> (Random::Random -> (Random::Random, e)) -> Random::Random -> Std::IO Random::Random`

`Segtree`の`fold`と`fold_all`が、素朴な畳み込みと一致することを確かめる

##### Parameters

- `name` : 失敗したときに表示する名前
- `to_m` : 要素の値から葉を作る関数
- `from_m` : モノイドの値から要素の値を読む関数
- `naive_op` : 要素の値どうしの演算
- `naive_unit` : `naive_op`の単位元
- `gen` : 要素の値をランダムに作る関数
- `rng` : 乱数生成器

#### gen_add

Type: `Random::Random -> (Random::Random, CPLib.Monoid::RangeAdd f Std::I64, Std::I64 -> Std::I64)`

区間加算の作用と、それを1要素に行う関数

#### gen_affine

Type: `Random::Random -> (Random::Random, CPLib.Monoid::RangeAffine CPLib.Monoid::WeightedSum CPLib.Monoid.Test::Mint, CPLib.Monoid.Test::Mint -> CPLib.Monoid.Test::Mint)`

アフィン変換の作用と、それを1要素に行う関数

#### gen_affine_nonneg

Type: `Random::Random -> (Random::Random, CPLib.Monoid::RangeAffine f Std::I64, Std::I64 -> Std::I64)`

係数が0以上のアフィン変換の作用と、それを1要素に行う関数

係数はほとんど1にし、値が溢れないようにする。

#### gen_assign

Type: `Random::Random -> (Random::Random, CPLib.Monoid::RangeAssign f Std::I64, Std::I64 -> Std::I64)`

区間代入の作用と、それを1要素に行う関数。代入しない作用も混ぜる

#### gen_mint

Type: `Random::Random -> (Random::Random, CPLib.Monoid.Test::Mint)`

法998244353の剰余環のランダムな値

#### gen_small

Type: `Random::Random -> (Random::Random, Std::I64)`

0以上100未満の整数

#### test

Type: `Std::IO ()`

#### test_init_weighted_sum

Type: `Std::IO ()`

`init`で作った`WeightedSum`の要素は重みが0で、作用を受けても変わらない

#### test_replace_digits

Type: `Std::IO ()`

ACL Beginner Contest E「Replace Digits」の入力例1：区間を数字で埋め、全体を10進数として読む

#### test_units

Type: `Std::IO ()`

各モノイドの単位元

## Types and aliases

### namespace CPLib.Monoid.Test

#### Mint

Defined as: `type Mint = CPLib.ZP::ZP CPLib.ZP::P998244353`

## Traits and aliases

## Trait implementations