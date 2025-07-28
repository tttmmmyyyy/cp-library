# CPLib.Arithmetic

Defined in cp-library@0.1.9

## Values

### namespace CPLib.Arithmetic

#### calc_gcd

Type: `Std::I64 -> Std::I64 -> Std::I64`

2つの整数の最大公約数（非負整数）を計算する

##### Parameters

- `a`: 整数
- `b`: 整数

#### create_prime_list

Type: `Std::I64 -> Std::Array Std::U32`

[0, n)の範囲での素数リストを作成する

##### Parameters

- `n` : 素数リストの上限（exclusive）

#### create_prime_table

Type: `Std::I64 -> BoolArray::BoolArray`

[0, n)の範囲での素数テーブルを作成する

配列（`BoolArray`）`table`は素数テーブルであり、`table.@(n)`が`true`の場合に`n`が素数であることを意味する。

注意：戻り値の要素に`@(n)`でアクセスするには`import BoolArray;`が必要です。

##### Parameters

- `n` : 素数テーブルの上限（exclusive）

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

制約：gcd(a, m) = 1

##### Parameters

- `a`: 整数
- `m`: 法

#### isqrt

Type: `Std::U64 -> Std::U64`

64ビット整数の平方根の整数部分を計算する

##### Parameters

- `x`: 64ビット整数

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

#### pow_mod_u

Type: `Std::U64 -> Std::U64 -> Std::U64 -> Std::U64`

`x^e`を`n`で割った余りを計算する（unsigned版）

##### Parameters

- `x`: 底 >= 0
- `e`: 指数 >= 0
- `m`: 法 > 0

## Types and aliases

## Traits and aliases

## Trait implementations