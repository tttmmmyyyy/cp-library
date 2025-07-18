# CPLib.Arithmetic

Defined in cp-library@0.1.0

## Values

### namespace CPLib.Arithmetic

#### calc_gcd

Type: `Std::I64 -> Std::I64 -> Std::I64`

2つの整数の最大公約数（非負整数）を計算する

##### Parameters

- `a`: 整数
- `b`: 整数

#### ext_gcd

Type: `Std::I64 -> Std::I64 -> (Std::I64, (Std::I64, Std::I64))`

拡張ユークリッドの互除法

2つの整数 `a`, `b` に対して、その最大公約数 `d >= 0` および、`ax + by = d` を満たす整数 `x`, `y` を求める

##### Returns

`(d, (x, y))`

##### Parameters

- `a`: 整数
- `b`: 整数

#### inv_mod

Type: `Std::I64 -> Std::I64 -> Std::I64`

`ax = 1 mod m`なる`x`のうち、`0 <= x < |m|`を満たすものを返す

制約：`a != 0 mod m`

##### Parameters

- `a`: 整数
- `m`: 法

#### pmod

Type: `Std::I64 -> Std::I64 -> Std::I64`

`x`を`m`で割った余りを非負で返す

C言語の%演算子とは異なり、負の数に対しても正の余りを返す

##### Parameters

- `m`: 除数
- `x`: 被除数

#### pow_mod

Type: `Std::I64 -> Std::I64 -> Std::I64 -> Std::I64`

`x^e`を`n`で割った余りを計算する

##### Parameters

- `x`: 底
- `e`: 指数 >= 0
- `m`: 法

## Types and aliases

## Traits and aliases

## Trait implementations