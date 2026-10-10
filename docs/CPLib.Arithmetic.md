# CPLib.Arithmetic

Defined in cp-library@0.15.0

## Values

### namespace CPLib.Arithmetic

#### add_mod

Type: `Std::I64 -> Std::I64 -> Std::I64 -> Std::I64`

`x + y`を`|m|`で割った余りを（非負で）返す

制約：m != 0

計算量：O(1)

##### Parameters

- `x`: 整数
- `y`: 整数
- `m`: 除数

#### calc_gcd

Type: `Std::I64 -> Std::I64 -> Std::I64`

2つの整数の最大公約数（非負整数）を計算する

制約：最大公約数 <= I64::maximum

計算量：O(log max(|a|, |b|))

##### Parameters

- `a`: 整数
- `b`: 整数

#### calc_primitive_root

Type: `Std::I64 -> Std::I64`

素数pの原始根r（1 <= r < p）を一つ求める。

https://cp-algorithms.com/algebra/primitive-root.html#algorithm-for-finding-a-primitive-root

制約：pは素数

計算量：O(sqrt(p))。pが`CPLib.ZP`に定義されている素数ならO(1)

##### Parameters

- `p`: 素数

#### create_prime_list

Type: `Std::I64 -> Std::Array Std::U32`

[0, n)の範囲での素数リストを作成する

制約：n >= 1

計算量：O(n log log n)

##### Parameters

- `n` : 素数リストの上限（exclusive）

#### create_prime_table

Type: `Std::I64 -> BoolArray::BoolArray`

[0, n)の範囲での素数テーブルを作成する

配列（`BoolArray`）`table`は素数テーブルであり、`table.@(n)`が`true`の場合に`n`が素数であることを意味する。

注意：戻り値の要素に`@(n)`でアクセスするには`import BoolArray;`が必要です。

制約：n >= 1

計算量：O(n log log n)

##### Parameters

- `n` : 素数テーブルの上限（exclusive）

##### Examples

```fix
import BoolArray;

let table = create_prime_table(10);
assert(|_|"", table.@(7));;
assert(|_|"", !table.@(9))
```

#### euler_tortient

Type: `Std::I64 -> Std::I64`

オイラーのトーシェント関数 φ(n) を計算する

制約：n >= 1

計算量：O(sqrt(n))

##### Parameters

- `n`: 正の整数

#### euler_tortient_table

Type: `Std::I64 -> Std::Array Std::I64`

0 <= i < n に対するオイラーのトーシェント関数 φ(i) の表を作成する

`table.@(i)` が φ(i) の値となる。ただし `table.@(0) = 0` とする。

計算量：O(n log log n)

##### Parameters

- `n`: 表の上限（exclusive）

#### ext_gcd

Type: `Std::I64 -> Std::I64 -> (Std::I64, (Std::I64, Std::I64))`

拡張ユークリッドの互除法

2つの整数 `a`, `b` に対して、その最大公約数 `d >= 0` および、`ax + by = d` を満たす整数 `x`, `y` を求める

制約：最大公約数 <= I64::maximum

計算量：O(log max(|a|, |b|))

##### Returns

`(d, (x, y))`

##### Parameters

- `a`: 整数
- `b`: 整数

##### Examples

```fix
let (d, (x, y)) = ext_gcd(12, 18);
assert_eq(|_|"", d, 6);;
assert_eq(|_|"", 12 * x + 18 * y, 6)
```

#### factorize

Type: `Std::I64 -> Std::Array (Std::U32, Std::U8)`

試し割りにより、数を素因数分解する（素因子と指数のペアの配列で返す）

制約：n >= 1, nの素因数 <= 4e9

計算量：O(sqrt(n))

##### Parameters

- `n`: 素因数分解する数

##### Returns

素因数分解の結果。
`(p, e)`の配列で、`p`は素因子、`e`はその指数を表す。`p`は昇順に並ぶ。
`n`が1の場合は空の配列を返す。

#### factorize_flat

Type: `Std::I64 -> Std::Array Std::U32`

試し割りにより、数を素因数分解する（素因子を重複ありのフラットな配列で返す）

制約：n >= 1, nの素因数 <= 4e9

計算量：O(sqrt(n))

##### Parameters

- `n`: 素因数分解する数

##### Returns

素因数分解の結果。素因子を昇順に並べた配列（同じ素因子はその指数分だけ繰り返し現れる）。
`n`が1の場合は空の配列を返す。

#### factorize_via_lp_table

Type: `Std::U32 -> Std::Array Std::U32 -> Std::Array (Std::U32, Std::U8)`

最小素因子テーブルを用いて、数を素因数分解する

制約：n < |lp_table|

計算量：O(log n)

##### Parameters

- `n`: 素因数分解する数
- `lp_table`: 最小素因子テーブル。最小素因子テーブルの定義は`linear_sieve`のコメントを参照。

##### Returns

素因数分解の結果。
`(p, e)`の配列で、`p`は素因子、`e`はその指数を表す。`p`は昇順に並ぶ。
`n`が0の場合は空の配列を返す。

##### Examples

```fix
let (lp, _) = linear_sieve(100_U32);
assert_eq(|_|"", factorize_via_lp_table(12_U32, lp), [(2_U32, 2_U8), (3_U32, 1_U8)]) // 12 = 2^2 * 3
```

#### floor_sum

Type: `Std::I64 -> Std::I64 -> Std::I64 -> Std::I64 -> Std::I64`

0 <= i < n に対する floor((a * i + b) / m) の和を計算する

ac-libraryのmathにある同名の関数の移植です。

制約：0 <= n < 2^32, 1 <= m < 2^32

計算量：O(log m)

##### Parameters

- `n`
- `m`
- `a`
- `b`

##### Examples

```fix
// floor(1/3) + floor(3/3) + floor(5/3) + floor(7/3) = 0 + 1 + 1 + 2
assert_eq(|_|"", floor_sum(4, 3, 2, 1), 4)
```

#### inv_mod

Type: `Std::I64 -> Std::I64 -> Std::I64`

`ax = 1 mod m`なる`x`のうち、`0 <= x < m`を満たすものを返す

制約：gcd(a, m) = 1, m >= 1

計算量：O(log m)

##### Parameters

- `m`: 法
- `a`: 整数

##### Examples

```fix
assert_eq(|_|"", 3.inv_mod(7), 5) // 3 * 5 = 15 = 1 mod 7
```

#### is_prime

Type: `Std::U64 -> Std::Bool`

Miller-Rabin 素数判定法（64bit版）

https://cp-algorithms.com/algebra/primality_tests.html#deterministic-version

計算量：O(log n)

##### Parameters

- `n`: 調べる数

#### is_prime_32

Type: `Std::U32 -> Std::Bool`

Miller-Rabin 素数判定法（32bit版）

https://cp-algorithms.com/algebra/primality_tests.html#deterministic-version

計算量：O(log n)

##### Parameters

- `n`: 調べる数

#### isqrt

Type: `Std::U64 -> Std::U64`

64ビット整数の平方根の整数部分を計算する

計算量：O(log s)

##### Parameters

- `s`: 64ビット整数

#### lift_crt

Type: `Std::Array Std::I64 -> Std::Array Std::I64 -> (Std::I64, Std::I64)`

連立合同方程式 P: x = r(i) (mod m(i)) を解きます。

解が存在するときは P <=> x = y (mod z), z = lcm(m(i)) となるような (y, z) を返します。

解が存在しない場合は、`(0, 0)`を返します。

制約：|rs| = |ms|, ms.@(i) >= 1, lcm(ms)が`I64`に収まる

計算量：O(n log lcm(ms))、n = |rs|

##### Parameters

- `rs`: r(i)の配列
- `ms`: m(i)の配列

##### Examples

```fix
// x = 2 (mod 3) かつ x = 3 (mod 5) <=> x = 8 (mod 15)
assert_eq(|_|"", lift_crt([2, 3], [3, 5]), (8, 15));;
// x = 0 (mod 2) かつ x = 1 (mod 4) には解がない
assert_eq(|_|"", lift_crt([0, 1], [2, 4]), (0, 0))
```

#### linear_sieve

Type: `Std::U32 -> (Std::Array Std::U32, Std::Array Std::U32)`

線形ふるいを用いて、[0, n)の範囲で、各数の最小の素因数を格納した配列と、素数のリストを作成する

計算量：O(n)

##### Parameters

- `n` : 上限（exclusive）

##### Returns

`(lp, ps)`
- `lp`: 最小素因子テーブル。長さnの配列で、`lp.@(i)`は`i`の最小の素因数。`lp.@(0)`, `lp.@(1)`は0。
- `ps`: [0, n)の範囲の素数のリスト

#### mul_mod

Type: `Std::I64 -> Std::I64 -> Std::I64 -> Std::I64`

`x * y`を`|m|`で割った余りを（非負で）返す

制約：m != 0

計算量：O(1)

##### Parameters

- `x`: 整数
- `y`: 整数
- `m`: 除数

#### pmod

Type: `Std::I64 -> Std::I64 -> Std::I64`

`x`を`m`で割った余りを非負で返す

C言語の%演算子とは異なり、負の数に対しても正の余りを返す

制約：m >= 1

計算量：O(1)

##### Parameters

- `m`: 除数
- `x`: 被除数

##### Examples

```fix
assert_eq(|_|"", (-7).pmod(3), 2)
```

#### pow_mod

Type: `Std::I64 -> Std::I64 -> Std::I64 -> Std::I64`

`x^e`を`m`で割った余りを計算する

制約：e >= 0, m >= 1

計算量：O(log e)

##### Parameters

- `e`: 指数
- `m`: 法
- `x`: 底

##### Examples

```fix
assert_eq(|_|"", 2.pow_mod(10, 1000), 24) // 2^10 = 1024
```

#### pow_mod_u

Type: `Std::U64 -> Std::U64 -> Std::U64 -> Std::U64`

`x^e`を`m`で割った余りを計算する（unsigned版）

制約：m >= 1

計算量：O(log e)

##### Parameters

- `e`: 指数
- `m`: 法
- `x`: 底

#### pythagorean_triples

Type: `Std::I64 -> Std::Array (Std::I64, Std::I64, Std::I64)`

原始ピタゴラス数`(a, b, c)`を列挙する

`a^2 + b^2 = c^2`を満たす正の整数の組`(a, b, c)`で、`gcd(a, b, c) = 1`を満たすものを列挙する

また、このような`a`, `b`は必ず片方が奇数でもう片方が偶数である。
この関数の戻り値では`a`が奇数、`b`が偶数となる。

制約：c_max >= 1

計算量：O(c_max log c_max)

##### Parameters

- `c_max`: `c`の上限（inclusive）

#### sub_mod

Type: `Std::I64 -> Std::I64 -> Std::I64 -> Std::I64`

`x - y`を`|m|`で割った余りを（非負で）返す

制約：m != 0

計算量：O(1)

##### Parameters

- `x`: 整数
- `y`: 整数
- `m`: 除数

## Types and aliases

## Traits and aliases

## Trait implementations