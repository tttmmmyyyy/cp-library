# CPLib.Memoize.Test

Defined in cp-library@0.14.0

## Values

### namespace CPLib.Memoize.Test

#### fib

Type: `[m : CPLib.Memoize::Memory, CPLib.Memoize::Memory::Key m = Std::I64, CPLib.Memoize::Memory::Value m = Std::U64] Std::I64 -> CPLib.Memoize::Memoize m Std::U64`

フィボナッチ数列 mod 2^64 を計算する

`m`はメモ化につかうメモリの型。`HashMap`や`Array`を呼び出し時に選択。

`fib`の結果をメモ化したいので`memoize(n) $ `で始める

#### sum_fib

Type: `[m : CPLib.Memoize::Memory, CPLib.Memoize::Memory::Key m = Std::I64, CPLib.Memoize::Memory::Value m = Std::U64] Std::I64 -> CPLib.Memoize::Memoize m Std::U64`

フィボナッチ数列の和 mod 2^64 を計算する

`sum_fib`の結果はメモ化しないので、`memoize`しない。

#### test

Type: `Std::IO ()`

#### test_array

Type: `Std::IO ()`

#### test_hashmap

Type: `Std::IO ()`

## Types and aliases

## Traits and aliases

## Trait implementations