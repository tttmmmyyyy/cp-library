# CPLib.Pell

Defined in cp-library@0.15.3

一般ペル方程式 x^2 - d y^2 = ±m を解く関数を与えるモジュール。

- `calc_pell_fundamental_solution`：ペル方程式 x^2 - d y^2 = ±1 の基本解
- `calc_general_pell_representatives`：x^2 - d y^2 = ±m の代表解のリスト。すべての解は、代表解に基本解のべきを掛けて得られる。
- `calc_general_pell_solutions`：x^2 - d y^2 = ±m の非負の解をすべて列挙するイテレータ

解の型は、型パラメータ`a : Integer`で選ぶ。解は指数的に大きくなるので、`I64`に収まらないときは多倍長整数の型（gmp-fix の`MPZ`など）を使う。

使用例：
```fix
// x^2 - 2 y^2 = ±1 の基本解は 1 + root(2)
assert_eq(|_|"", (calc_pell_fundamental_solution(2) : (I64, I64)), (1, 1));;
// x^2 - 2 y^2 = ±7 の非負の解を4つ
let sols : Array (I64, I64) = calc_general_pell_solutions(2, 7).take(4).to_array;
assert(|_|"", sols.to_iter.check_all(|(x, y)| (x * x - 2 * y * y).abs == 7))
```

## アルゴリズム

正の非平方数dに対し、w = root(d) とする。

Z[w] の単数は、符号を除いて eps^n (n は整数) という形である。epsは基本単数。

t in Q[w] が簡約であるとは、1 < t, -1 < t' < 0 であることをいう（t'は共役）。

t in Q[w] \ Q に対し、対応する格子を L(t) = Z + tZ と定義する。

t in Q[w] の連分数展開 t(0) = t, t(i) = a(i) + 1/t(i+1) （a(i) は t(i) の整数部分）は、途中から簡約になり、初めて簡約になった場所から巡回する（Lagrange, Galois）。

t を連分数展開して u になったとき、展開は t = g u (1次分数変換) となる g in GL2(Z) を与え、ここから L(t) = r L(u) となる r in Q[w] が得られる。

定理（格子 L(t) の極小点を使って示せる）：
t, u in Q[w] が簡約で、r in Q[w], |r| <= 1 に対し L(t) = r L(u) となっているとする。
このとき、ある i について t(i) = u であり、r はこの連分数展開から上の方法で（符号を除いて）得られる。

### ペル方程式 x^2 - dy^2 = ±1

これは Z[w] の単元（ノルムが±1の元）を求める問題である。これは Z[w] = r Z[w] となる元 r に他ならない。
Z[w] = L(s + w) (s = floor(w)) であり、s + w は簡約である。
よって、s + w を連分数展開すると、|r| <= 1 な単数がすべて得られる。特に、r = 1 を除いて初めて得たそのような r は基本単数の逆数であり、その逆数が基本単数である。

### 一般ペル方程式 x^2 - dy^2 = ±m

m を m / (平方数) に取り替えることで、x, y が互いに素な解（原始解）を求める問題に帰着できる。

以下の集合の対応がある：

```
  { x^2 - dy^2 = ±m の原始解の単元倍による軌道 }
= { Z[w] のイデアル I で、原始的で、指数 |Z[w]/I| が |m| で、単項生成なもの } ※ イデアルが原始的とは、k Z[w] (k > 0 は整数) に含まれないイデアルのこと。
⊂ { Z[w] のイデアル I で、原始的で、指数 |Z[w]/I| が |m| なもの }
= { 環準同型 Z[w] -> Z/m } ※ Kernelで対応
= { z in Z/m : z^2 = d } ※ w の行き先で対応
```

z in Z/m : z^2 = d をとったとき、対応するイデアルは I(z) = |m|Z + (z + w)Z である。
これが単項生成であるかどうかを判定し、生成元をひとつ求め、すべての単元を乗算すればよい。

t = (z + w)/|m| とおくと、I(z) = |m| L(t) であり、I(z) が単項生成であるとは、L(t) = r Z[w] となる r in Q[w] があることに他ならない。
よって、t を連分数展開することで L(t) = r L(u) なる r, u の組を作り、L(u) = Z[w] となることがあるか（つまり u in Z[w] となるか）を見れば良い。
連分数展開はいずれ簡約になり、そのあとは巡回するので、はじめて簡約になってから再訪するまでに u in Z[w] とならなければ、単項生成ではないことが言える。

## Values

### namespace CPLib.Pell

#### calc_general_pell_representatives

Type: `[a : CPLib.Trait::Integer] Std::I64 -> Std::I64 -> Std::Array (a, a)`

一般ペル方程式 x^2 - d y^2 = ±m の代表解のリストを求める

ペル方程式 x^2 - d y^2 = ±1 の基本解を e とする。
一般ペル方程式 x^2 - d y^2 = ±m の解は、符号をのぞき、代表解のどれか r から r e^n （nは整数）として一意に得られる。
ここで、解 (x, y) を実数 x + y root(d) と同一視している。

代表解のリストに、ある代表解 x + y root(d) と、その共役 x - y root(d) を単数倍したものの両方が現れることがある。
これは無駄ではなく、e^n を乗算することですべての解を生成するためには、両方が必要である。

型`a`には、代表解を表せる大きさの整数の型を指定する。代表解は基本解と同程度に大きくなることがあり、`I64`に収まるとは限らない。
戻り値の型を多倍長整数の型（gmp-fix の`MPZ`など）にすれば、どの`d`、`m`でも代表解が求まる。例：`(calc_general_pell_representatives(526, 7) : Array (MPZ, MPZ))`。

制約：d > 0、dは平方数でない、m != 0

##### Parameters

- `d` : x^2 - d y^2 = ±m の d
- `m` : x^2 - d y^2 = ±m の m

##### Examples

```fix
// x^2 - 2 y^2 = ±7 の解は、3 + root(2) と -3 + root(2) の単数倍
assert_eq(|_|"", (calc_general_pell_representatives(2, 7) : Array (I64, I64)).sort, [(-3, 1), (3, 1)])
```

#### calc_general_pell_solutions

Type: `[?it : Std::Iterator, a : CPLib.Trait::Integer, Std::Iterator::Item ?it = (a, a)] Std::I64 -> Std::I64 -> ?it`

一般ペル方程式 x^2 - d y^2 = ±m の非負の解をすべて列挙するイテレータを作る

x >= 0, y >= 0 を満たす解 (x, y) を、重複なく、すべて列挙する。解が無限にあれば無限に続き、なければ空である。
解は大きさの順には並ばない。

解は指数的に大きくなる。型`a`の範囲を超える大きさの解に達すると、演算がオーバーフローする。
`I64`では、オーバーフローした値が出るか、`--check-integer-operations`を付けてビルドしたときはプログラムが止まる。
範囲を超える解まで列挙したいときは、要素の型を多倍長整数の型（gmp-fix の`MPZ`など）にする。例：`(calc_general_pell_solutions(2, 7).take(100).to_array : Array (MPZ, MPZ))`。

制約：d > 0、dは平方数でない、m != 0

計算量：最初の要素を得るまでに、`calc_general_pell_representatives`と`calc_pell_fundamental_solution`の計算。
その後は、1要素あたり、代表解の個数に比例する回数の`a`の演算（ならし）。

##### Parameters

- `d` : x^2 - d y^2 = ±m の d
- `m` : x^2 - d y^2 = ±m の m

##### Examples

```fix
let sols : Array (I64, I64) = calc_general_pell_solutions(2, 7).take(4).to_array;
assert(|_|"", sols.to_iter.check_all(|(x, y)| (x * x - 2 * y * y).abs == 7))
```

#### calc_pell_fundamental_solution

Type: `[a : CPLib.Trait::Integer] Std::I64 -> (a, a)`

ペル方程式 x^2 - d y^2 = ±1 の基本解を求める

戻り値を e とするとき、解の全体は、符号をのぞき、e^n （nは整数）である。
ここで、解 (x, y) を実数 x + y root(d) と同一視している。

型`a`には、解を表せる大きさの整数の型を指定する。`I64`では、`d`によっては基本解が収まらない（例：d = 526 の基本解は x = 84056091546952933775 で、`I64`の最大値を超える）。
戻り値の型を多倍長整数の型（gmp-fix の`MPZ`など）にすれば、どの`d`でも基本解が求まる。例：`(calc_pell_fundamental_solution(526) : (MPZ, MPZ))`。

制約：d > 0、dは平方数でない

計算量：O(r)回の`a`の演算。r は root(d) の連分数展開の周期の長さで、r = O(root(d) log(d))。

##### Parameters

- `d` : x^2 - d y^2 = ±1 の d

##### Returns

x > 0, y > 0 を満たす (x, y)。x + y root(d) は x^2 - d y^2 = ±1 の解のうち 1 より大きい最小のもの。

##### Examples

```fix
assert_eq(|_|"", (calc_pell_fundamental_solution(2) : (I64, I64)), (1, 1));; // 1^2 - 2 * 1^2 = -1
assert_eq(|_|"", (calc_pell_fundamental_solution(7) : (I64, I64)), (8, 3)) // 8^2 - 7 * 3^2 = 1
```

## Types and aliases

## Traits and aliases

## Trait implementations