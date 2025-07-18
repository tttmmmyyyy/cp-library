# CPLib.ZP

Defined in cp-library@0.1.0

## Values

### namespace CPLib.ZP::PrimeProvider

#### create

Type: `[p : CPLib.ZP::PrimeProvider] p`

#### value

Type: `[p : CPLib.ZP::PrimeProvider] p -> Std::U32`

### namespace CPLib.ZP::ZP

#### inv

Type: `[p : CPLib.ZP::PrimeProvider] CPLib.ZP::ZP p -> CPLib.ZP::ZP p`

`ZP p`の逆元を求める。

0を与えた場合はプログラムを終了する。

##### Parameters

- `x` : `ZP p`型の整数

#### make

Type: `[p : CPLib.ZP::PrimeProvider] Std::I64 -> CPLib.ZP::ZP p`

`I64`から素数を作成する

##### Parameters

- `x` : `I64`型の整数

#### power

Type: `[p : CPLib.ZP::PrimeProvider] Std::I64 -> CPLib.ZP::ZP p -> CPLib.ZP::ZP p`

x^e mod p を計算する。

xが0かつeが負のときはプログラムを終了する。

##### Parameters

- `x` : `ZP p`型の数
- `e` : `I64`型の指数

## Types and aliases

### namespace CPLib.ZP

#### P1000000007

Defined as: `type P1000000007 = unbox struct { ...fields... }`

#### P1000000009

Defined as: `type P1000000009 = unbox struct { ...fields... }`

#### P998244353

Defined as: `type P998244353 = unbox struct { ...fields... }`

#### ZP

Defined as: `type ZP p = unbox struct { ...fields... }`

素数`p`を法とする整数の環

##### field `value`

Type: `Std::U32`

##### field `prime`

Type: `p`

## Traits and aliases

### namespace CPLib.ZP

#### trait `p : PrimeProvider`

##### method `create`

Type: `p`

##### method `value`

Type: `p -> Std::U32`

## Trait implementations

### impl `CPLib.ZP::P1000000007 : CPLib.ZP::PrimeProvider`

### impl `CPLib.ZP::P1000000009 : CPLib.ZP::PrimeProvider`

### impl `CPLib.ZP::P998244353 : CPLib.ZP::PrimeProvider`

### impl `[p : CPLib.ZP::PrimeProvider] CPLib.ZP::ZP p : Std::Add`

### impl `[p : CPLib.ZP::PrimeProvider] CPLib.ZP::ZP p : Std::Div`

### impl `[p : CPLib.ZP::PrimeProvider] CPLib.ZP::ZP p : Std::Eq`

### impl `[p : CPLib.ZP::PrimeProvider] CPLib.ZP::ZP p : Std::Mul`

### impl `[p : CPLib.ZP::PrimeProvider] CPLib.ZP::ZP p : Std::Neg`

### impl `[p : CPLib.ZP::PrimeProvider] CPLib.ZP::ZP p : Std::Sub`

### impl `CPLib.ZP::ZP p : Std::ToString`