# CPLib.LSegtree.Test

Defined in cp-library@0.11.1

## Values

### namespace CPLib.LSegtree.Test

#### gen_random_alphabetical_string

Type: `Random::Random -> (Random::Random, Std::String)`

ランダムな数文字のアルファベット文字列を生成する

#### test

Type: `Std::IO ()`

#### test_random

Type: `Std::Bool -> Random::Random -> Std::IO Random::Random`

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