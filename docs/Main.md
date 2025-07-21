# Main

Defined in cp-library@0.1.0

fix run で書きかけのテストコードとかを走らせたいときなどに使ってください。
でもコミットしないで！

## Values

### namespace Main

#### main

Type: `Std::IO ()`

### namespace Main::I64Add

#### make

Type: `Std::I64 -> Main::I64Add`

### namespace Main::I64Max

#### make

Type: `Std::I64 -> Main::I64Max`

## Types and aliases

### namespace Main

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

## Traits and aliases

## Trait implementations

### impl `Main::I64Add : CPLib.Trait::Action`

加法モノイドの最大値モノイドに対する作用

### impl `Main::I64Add : CPLib.Trait::Monoid`

### impl `Main::I64Max : CPLib.Trait::Monoid`