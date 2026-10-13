# CPLib.LSegtree.Test

Defined in cp-library@0.15.0

## Values

### namespace CPLib.LSegtree.Test

#### gen_random_alphabetical_string

Type: `Random::Random -> (Random::Random, Std::String)`

ランダムな数文字のアルファベット文字列を生成する

#### is_sorted

Type: `Std::String -> Std::Bool`

文字列の文字が昇順に並んでいるか

#### test

Type: `Std::IO ()`

#### test_empty

Type: `Std::IO ()`

要素数0の木で、空区間への作用と畳み込みができる

#### test_random

Type: `Std::Bool -> Std::I64 -> Std::I64 -> Random::Random -> Std::IO Random::Random`

n要素のセグメント木に対してランダムな操作をops回行い、foldの結果を愚直な計算と比べる

##### Parameters

- `is_build` : セグメント木をbuildで構築するかどうか。そうでないときはinitで構築する
- `n` : 要素数
- `ops` : 操作の回数
- `rng` : 乱数生成器

#### test_search

Type: `Random::Random -> Std::IO Random::Random`

fold_all、calc_max_right、calc_min_leftが、文書の条件を満たす値を返すことのテスト

要素数0から20の木にランダムな区間への作用を重ねていき、作用のたびに、すべての端について調べる。
条件には、文字が昇順に並んでいることと、長さが3以下であることを使う。

#### test_search_large

Type: `Random::Random -> Std::IO Random::Random`

大きい木で、calc_max_rightとcalc_min_leftが返す端を、条件から決まる端と比べるテスト

条件は「畳み込みの長さがt以下で、端から先の全要素を連結した文字列の先頭（calc_min_leftでは、端より前の末尾）に一致する」とする。
高い段のノードの値と、その祖先に残る作用が正しく使われることを確かめるためである。

#### test_speed

Type: `Std::IO ()`

### namespace CPLib.LSegtree.Test::I64Add

#### make

Type: `Std::I64 -> CPLib.LSegtree.Test::I64Add`

### namespace CPLib.LSegtree.Test::I64Max

#### make

Type: `Std::I64 -> CPLib.LSegtree.Test::I64Max`

### namespace CPLib.LSegtree.Test::ShiftAlphabet

#### make

Type: `Std::I64 -> Std::I64 -> CPLib.LSegtree.Test::ShiftAlphabet`

### namespace CPLib.LSegtree.Test::StrConcat

#### make

Type: `Std::String -> CPLib.LSegtree.Test::StrConcat`

## Types and aliases

### namespace CPLib.LSegtree.Test

#### I64Add

Defined as: `type I64Add = unbox struct { ...fields... }`

加法モノイド

##### field `v`

Type: `Std::I64`

#### I64Max

Defined as: `type I64Max = unbox struct { ...fields... }`

最大値モノイド

##### field `v`

Type: `Std::I64`

#### ShiftAlphabet

Defined as: `type ShiftAlphabet = unbox struct { ...fields... }`

文字ごとにアフィン変換（mod 26）を行うモノイド

##### field `a`

Type: `Std::I64`

##### field `b`

Type: `Std::I64`

#### StrConcat

Defined as: `type StrConcat = unbox struct { ...fields... }`

文字列の結合に関するモノイド

##### field `v`

Type: `Std::String`

## Traits and aliases

## Trait implementations

### impl `CPLib.LSegtree.Test::I64Add : CPLib.Trait::Action`

加法モノイドの最大値モノイドに対する作用

### impl `CPLib.LSegtree.Test::I64Add : CPLib.Trait::Monoid`

### impl `CPLib.LSegtree.Test::I64Max : CPLib.Trait::Monoid`

### impl `CPLib.LSegtree.Test::ShiftAlphabet : CPLib.Trait::Action`

作用の定義

### impl `CPLib.LSegtree.Test::ShiftAlphabet : CPLib.Trait::Monoid`

### impl `CPLib.LSegtree.Test::ShiftAlphabet : Std::ToString`

### impl `CPLib.LSegtree.Test::StrConcat : CPLib.Trait::Monoid`

### impl `CPLib.LSegtree.Test::StrConcat : Std::Eq`

### impl `CPLib.LSegtree.Test::StrConcat : Std::ToString`