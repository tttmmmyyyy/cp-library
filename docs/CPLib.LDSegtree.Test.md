# CPLib.LDSegtree.Test

Defined in cp-library@0.11.1

## Values

### namespace CPLib.LDSegtree.Test

#### gen_random_alphabetical_string

Type: `Random::Random -> (Random::Random, Std::String)`

ランダムな数文字のアルファベット文字列を生成する

#### op

Type: `(Std::String, Std::String) -> Std::String`

文字列の結合に関するモノイド

#### test

Type: `Std::IO ()`

#### test_random

Type: `Std::Bool -> Random::Random -> Std::IO Random::Random`

#### test_speed

Type: `Std::IO ()`

#### unit

Type: `Std::String`

### namespace CPLib.LDSegtree.Test::ShiftAlphabet

#### a_op

Type: `(CPLib.LDSegtree.Test::ShiftAlphabet, CPLib.LDSegtree.Test::ShiftAlphabet) -> CPLib.LDSegtree.Test::ShiftAlphabet`

#### a_unit

Type: `CPLib.LDSegtree.Test::ShiftAlphabet`

#### act

Type: `(Std::String, CPLib.LDSegtree.Test::ShiftAlphabet) -> Std::String`

#### make

Type: `Std::I64 -> Std::I64 -> CPLib.LDSegtree.Test::ShiftAlphabet`

## Types and aliases

### namespace CPLib.LDSegtree.Test

#### ShiftAlphabet

Defined as: `type ShiftAlphabet = unbox struct { ...fields... }`

文字ごとにアフィン変換（mod 26）を行うモノイド

##### field `a`

Type: `Std::I64`

##### field `b`

Type: `Std::I64`

## Traits and aliases

## Trait implementations

### impl `CPLib.LDSegtree.Test::ShiftAlphabet : Std::ToString`