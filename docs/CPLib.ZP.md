# CPLib.ZP

Defined in cp-library@0.1.0

素数`p`を法とする整数の環の型`ZP p`を与えるモジュール。

素数`p`は静的でなければならない（コンパイル時に決まる必要がある）。

素数`p`は型パラメータとして与える。例として、p = 17 としたい場合、
- 空の型（フィールドを持たないunboxedな型）`P17`を作成：`type P17 = unbox struct {}`.
- `P17 : PrimeProvider`を実装する。この際`PrimeProvider::value`関数で17を返すようにする：`value = |_| 17_U32;`
すると`ZP P17`が環"Z/(17)"を表す型となる。

`P100000007`、`P1000000009`, `P998244353` はこのモジュールに定義されている。

使用例：
```
module Main;

import CPLib.ZP;

type P17 = unbox struct {};

impl P17 : PrimeProvider {
    create = P17 {};
    value = |p| 17_U32;
}

main : IO ();
main = (
    let zp = ZP::make(-5) : ZP P17;
    let zp = zp * zp;
    assert_eq(|_|"case 1", zp.@value, 8_U32);; // (-5)*(-5) = 25 = 8 mod 17
    pure()
);
```

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