# CPLib.Trait

Defined in cp-library@0.6.7

## Values

### namespace CPLib.Trait::Action

#### act

Type: `[a : CPLib.Trait::Action] a -> CPLib.Trait::Action::Set a -> CPLib.Trait::Action::Set a`

作用

### namespace CPLib.Trait::Inf

#### inf

Type: `[a : CPLib.Trait::Inf] a`

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

#### trait `a : Action`

作用のトレイト

右作用なのか左作用なのかは使う側が決める

##### type `Set`

Defined as: `Set a`

作用を受ける集合の型

##### method `act`

Type: `a -> CPLib.Trait::Action::Set a -> CPLib.Trait::Action::Set a`

作用

#### trait `a : Inf`

各型の無限大の値

##### method `inf`

Type: `a`

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

### impl `Std::F32 : CPLib.Trait::Inf`

### impl `Std::F64 : CPLib.Trait::Inf`

### impl `Std::I16 : CPLib.Trait::Inf`

### impl `Std::I32 : CPLib.Trait::Inf`

### impl `Std::I64 : CPLib.Trait::Inf`

### impl `Std::I8 : CPLib.Trait::Inf`

### impl `Std::U16 : CPLib.Trait::Inf`

### impl `Std::U32 : CPLib.Trait::Inf`

### impl `Std::U64 : CPLib.Trait::Inf`

### impl `Std::U8 : CPLib.Trait::Inf`