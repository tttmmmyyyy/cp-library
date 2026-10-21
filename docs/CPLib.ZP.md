# CPLib.ZP

Defined in cp-library@0.15.2

素数`p`を法とする整数の環の型`ZP p`を与えるモジュール。

法`p`は静的でなければなりません（コンパイル時に決まる必要があります）。

制約：p < 2^31。`inv`、`/`、`fft`、`primitive_root`は、pが素数であることを要します。それ以外は、pが素数でなくても動きます。
法が実行時に動的に変わる場合は、`CPLib.Arithmetic`の`add_mod`・`sub_mod`・`mul_mod`・`pow_mod`・`inv_mod`を使ってください。

法`p`は型パラメータとして与えます。例として、p = 17 としたい場合は、

- 空の型（フィールドを持たないunboxedな型）`P17`を作ります：`type P17 = unbox struct {}`
- `P17 : PrimeProvider`を実装し、`PrimeProvider::value`関数で17を返すようにします：`value = |_| 17_U32;`

すると`ZP P17`が環"Z/(17)"を表す型になります。

いくつかの有名な素数nに対する`PrimeProvider`の型`Pn`は、このモジュールに定義されています。

使用例：
```fix
import CPLib.ZP;

type P17 = unbox struct {};

impl P17 : PrimeProvider {
    create = P17 {};
    value = |_| 17_U32;
}

main : IO () = (
    let x = zp(-5) : ZP P17;
    let y = x * x;
    assert_eq(|_|"", y.@value, 8_U32) // (-5)*(-5) = 25 = 8 mod 17
);
```

## Values

### namespace CPLib.ZP

#### fft

Type: `[p : CPLib.ZP::PrimeProvider] CPLib.ZP::FFTDirection -> Std::Array (CPLib.ZP::ZP p) -> Std::Array (CPLib.ZP::ZP p)`

`ZP p`型の配列に対して高速フーリエ変換を行う

入力の長さを2のべき乗に切り上げ、末尾を0で埋めてから変換する。返る配列の長さは切り上げた長さである（長さ3なら4）。順変換して逆変換すると、元の配列の末尾に0を足した、切り上げた長さの配列が返る。

制約：2^c | (p-1) かつ |x| <= 2^c なる c が存在する

計算量：O(n log n + sqrt(p))、n = |x|。pがこのモジュールに定義されている素数ならO(n log n)

##### Parameters

- `dir` : FFTの方向（順方向か逆方向か）
- `x` : `ZP p`型の配列

#### inv

Type: `[p : CPLib.ZP::PrimeProvider] CPLib.ZP::ZP p -> CPLib.ZP::ZP p`

`ZP p`の逆元を求める。

0を与えた場合はプログラムを終了する。

計算量：O(log p)

##### Parameters

- `x` : `ZP p`型の整数

#### make

**Deprecated**: Use `CPLib.ZP::zp` instead.

Type: `[p : CPLib.ZP::PrimeProvider] Std::I64 -> CPLib.ZP::ZP p`

`zp`の別名（非推奨）

#### primitive_root

Type: `[p : CPLib.ZP::PrimeProvider] CPLib.ZP::ZP p`

法pの原始根を一つ得る

計算量：O(sqrt(p))。pがこのモジュールに定義されている素数ならO(1)

#### zp

Type: `[p : CPLib.ZP::PrimeProvider] Std::I64 -> CPLib.ZP::ZP p`

`I64`から`ZP p`の値を作成する

計算量：O(1)

##### Parameters

- `x` : `I64`型の整数

### namespace CPLib.ZP::PrimeProvider

#### create

Type: `[p : CPLib.ZP::PrimeProvider] p`

Trait member of `CPLib.ZP::PrimeProvider`

#### value

Type: `[p : CPLib.ZP::PrimeProvider] p -> Std::U32`

Trait member of `CPLib.ZP::PrimeProvider`

### namespace CPLib.ZP::ZP

#### @prime

Type: `CPLib.ZP::ZP p -> p`

`x`の法`p`を与える`PrimeProvider`の値を返す

##### Parameters

- `x` : `ZP p`型の整数

#### @value

Type: `CPLib.ZP::ZP p -> Std::U32`

`x`を[0, p)の整数として返す

##### Parameters

- `x` : `ZP p`型の整数

## Types and aliases

### namespace CPLib.ZP

#### FFTDirection

Defined as: `type FFTDirection = unbox union { ...variants... }`

高速フーリエ変換の方向（順方向か逆方向か）を表す型

##### variant `forward`

Type: `()`

##### variant `inverse`

Type: `()`

#### P1000000007

Defined as: `type P1000000007 = unbox struct { ...fields... }`

#### P1000000009

Defined as: `type P1000000009 = unbox struct { ...fields... }`

#### P167772161

Defined as: `type P167772161 = unbox struct { ...fields... }`

NTT-friendly prime (2^25 | p-1)

#### P469762049

Defined as: `type P469762049 = unbox struct { ...fields... }`

NTT-friendly prime (2^26 | p-1)

#### P754974721

Defined as: `type P754974721 = unbox struct { ...fields... }`

NTT-friendly prime (2^24 | p-1)

#### P998244353

Defined as: `type P998244353 = unbox struct { ...fields... }`

NTT-friendly prime (2^23 | p-1)

#### ZP

Defined as: `type ZP p = unbox struct { ...fields... }`

素数`p`を法とする整数の環

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

### impl `CPLib.ZP::P167772161 : CPLib.ZP::PrimeProvider`

### impl `CPLib.ZP::P469762049 : CPLib.ZP::PrimeProvider`

### impl `CPLib.ZP::P754974721 : CPLib.ZP::PrimeProvider`

### impl `CPLib.ZP::P998244353 : CPLib.ZP::PrimeProvider`

### impl `[p : CPLib.ZP::PrimeProvider] CPLib.ZP::ZP p : Std::Add`

### impl `[p : CPLib.ZP::PrimeProvider] CPLib.ZP::ZP p : Std::Div`

### impl `[p : CPLib.ZP::PrimeProvider] CPLib.ZP::ZP p : Std::Eq`

### impl `[p : CPLib.ZP::PrimeProvider] CPLib.ZP::ZP p : Std::Mul`

### impl `[p : CPLib.ZP::PrimeProvider] CPLib.ZP::ZP p : Std::Neg`

### impl `[p : CPLib.ZP::PrimeProvider] CPLib.ZP::ZP p : Std::One`

### impl `[p : CPLib.ZP::PrimeProvider] CPLib.ZP::ZP p : Std::Sub`

### impl `CPLib.ZP::ZP p : Std::ToString`

### impl `[p : CPLib.ZP::PrimeProvider] CPLib.ZP::ZP p : Std::Zero`