# CPLib.Arithmetic

Defined in cp-library@0.7.5

## Values

### namespace CPLib.Arithmetic

#### add_mod

Type: `Std::I64 -> Std::I64 -> Std::I64 -> Std::I64`

`x + y`を`m`で割った余りを（非負で）返す

##### Parameters

- `x`: 整数
- `y`: 整数
- `m`: 除数 != 0

#### calc_gcd

Type: `Std::I64 -> Std::I64 -> Std::I64`

2つの整数の最大公約数（非負整数）を計算する

##### Parameters

- `a`: 整数
- `b`: 整数

#### calc_primitive_root

Type: `Std::I64 -> Std::I64`

素数pの原始根r（1 <= r < p）を一つ求める。

https://cp-algorithms.com/algebra/primitive-root.html#algorithm-for-finding-a-primitive-root

注意：現状、この関数はp-1の素因数分解を素朴なO(sqrt(p))の方法で行います。

##### Parameters

- `p`: 素数

#### create_prime_list

Type: `Std::I64 -> Std::Array Std::U32`

[0, n)の範囲での素数リストを作成する

##### Parameters

- `n` : 素数リストの上限（exclusive）

#### create_prime_table

Type: `Std::I64 -> BoolArray::BoolArray`

[0, n)の範囲での素数テーブルを作成する

配列（`BoolArray`）`table`は素数テーブルであり、`table.@(n)`が`true`の場合に`n`が素数であることを意味する。

注意：戻り値の要素に`@(n)`でアクセスするには``が必要です。

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

#### floor_sum

Type: `Std::I64 -> Std::I64 -> Std::I64 -> Std::I64 -> Std::I64`

0 <= i < n に対する floor((a * i + b) / m) の和を計算する

ac-libraryのmathにある同名の関数の移植です。

##### Parameters

- `n`
- `m`
- `a`
- `b`

#### inv_mod

Type: `Std::I64 -> Std::I64 -> Std::I64`

`ax = 1 mod m`なる`x`のうち、`0 <= x < |m|`を満たすものを返す

制約：gcd(a, m) = 1

##### Parameters

- `m`: 法 > 0
- `a`: 整数

#### is_prime

Type: `Std::U64 -> Std::Bool`

Miller-Rabin 素数判定法（64bit版）

https://cp-algorithms.com/algebra/primality_tests.html#deterministic-version

##### Parameters

- `n`: 調べる数

#### is_prime_32

Type: `Std::U32 -> Std::Bool`

Miller-Rabin 素数判定法（32bit版）

https://cp-algorithms.com/algebra/primality_tests.html#deterministic-version

##### Parameters

- `n`: 調べる数

#### isqrt

Type: `Std::U64 -> Std::U64`

64ビット整数の平方根の整数部分を計算する

##### Parameters

- `x`: 64ビット整数

#### lift_crt

Type: `Std::Array Std::I64 -> Std::Array Std::I64 -> (Std::I64, Std::I64)`

連立合同方程式 P: x = r(i) (mod m(i)) を解きます。

解が存在するときは P <=> x = y (mod z), z = lcm(m(i)) となるような (y, z) を返します。

解が存在しない場合は、`(0, 0)`を返します。

制約や計算量オーダーは https://atcoder.github.io/ac-library/master/document_ja/math.html の`crt`と同様です。

##### Parameters

- `rs`: r(i)の配列
- `ms`: m(i) >= 1の配列。r(i)と同じ長さ。

#### mul_mod

Type: `Std::I64 -> Std::I64 -> Std::I64 -> Std::I64`

`x * y`を`m`で割った余りを（非負で）返す

##### Parameters

- `x`: 整数
- `y`: 整数
- `m`: 除数 != 0

#### pmod

Type: `Std::I64 -> Std::I64 -> Std::I64`

`x`を`m`で割った余りを非負で返す

C言語の%演算子とは異なり、負の数に対しても正の余りを返す

##### Parameters

- `m`: 除数 > 0
- `x`: 被除数

#### pow_mod

Type: `Std::I64 -> Std::I64 -> Std::I64 -> Std::I64`

`x^e`を`n`で割った余りを計算する

##### Parameters

- `e`: 指数 >= 0
- `m`: 法 > 0
- `x`: 底

#### pow_mod_u

Type: `Std::U64 -> Std::U64 -> Std::U64 -> Std::U64`

`x^e`を`n`で割った余りを計算する（unsigned版）

##### Parameters

- `e`: 指数 >= 0
- `m`: 法 > 0
- `x`: 底 >= 0

#### sub_mod

Type: `Std::I64 -> Std::I64 -> Std::I64 -> Std::I64`

`x - y`を`m`で割った余りを（非負で）返す

##### Parameters

- `x`: 整数
- `y`: 整数
- `m`: 除数 != 0

## Types and aliases

## Traits and aliases

## Trait implementations