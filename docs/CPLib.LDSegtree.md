# CPLib.LDSegtree

Defined in cp-library@0.15.0

モノイド構造および作用が動的に決められる遅延伝搬セグメント木

コンストラクタでモノイドおよび作用を指定する点以外は、`CPLib.LSegtree`と同じです。
モノイド構造・作用が静的に決まる場合は`CPLib.LSegtree`の方が高速です。

制約・計算量の n は要素数です。計算量は`op`, `act_op`, `act`がO(1)で動くとしたものです。

制約：作用は次を満たす（`a`, `b`は作用、`x`, `y`は値）
- act(act_unit, x) = x
- act(a, op(x, y)) = op(act(a, x), act(a, y))
- act(act_op(a, b), x) = act(b, act(a, x))

## Examples

```fix
// 区間への加算と、区間の最大値の取得ができるセグメント木
let tree = build(
    [1, 2, 3],
    minimum, |(x, y)| max(x, y), // 値モノイド：最大値
    0, |(a, b)| a + b,                // 作用モノイド：加法
    |(a, x)| x + a                    // 作用：加算
);
let tree = tree.act_range(0, 2, 10); // [11, 12, 3]
assert_eq(|_|"", tree.fold(1, 3), 12)
```

## Values

### namespace CPLib.LDSegtree

#### @

Type: `Std::I64 -> CPLib.LDSegtree::LDSegtree m a -> m`

セグメント木の要素を取得する

制約：0 <= i < n

計算量：O(log n)

##### Parameters

- `i` : インデックス（0-indexed）
- `tree` : セグメント木

#### @size

Type: `CPLib.LDSegtree::LDSegtree m a -> Std::I64`

セグメント木の要素数を取得する

計算量：O(1)

##### Parameters

- `tree` : セグメント木

#### act_at

Type: `Std::I64 -> a -> CPLib.LDSegtree::LDSegtree m a -> CPLib.LDSegtree::LDSegtree m a`

1つの要素に作用を適用する

`act_range(i, i + 1, a)`と同じ結果になる。

制約：0 <= i < n

計算量：O(log n)

##### Parameters

- `i` : インデックス（0-indexed）
- `a` : 作用
- `tree` : セグメント木

#### act_range

Type: `Std::I64 -> Std::I64 -> a -> CPLib.LDSegtree::LDSegtree m a -> CPLib.LDSegtree::LDSegtree m a`

半開区間[l, r)に右から作用を適用する

制約：0 <= l <= r <= n

計算量：O(log n)

##### Parameters

- `l` : 区間の左端 (0-indexed)
- `r` : 区間の右端 (0-indexed, exclusive)
- `a` : 適用する作用
- `tree` : セグメント木

#### build

Type: `Std::Array m -> m -> ((m, m) -> m) -> a -> ((a, a) -> a) -> ((a, m) -> m) -> CPLib.LDSegtree::LDSegtree m a`

要素の配列からセグメント木を作成する

計算量：O(n)

##### Parameters

- `elems` : セグメント木の要素を格納する配列
- `unit` : 値モノイドの単位元
- `op` : 値モノイドの演算子
- `act_unit` : 作用モノイドの単位元
- `act_op` : 作用モノイドの演算子
- `act` : 右作用

#### calc_max_right

Type: `Std::I64 -> (m -> Std::Bool) -> CPLib.LDSegtree::LDSegtree m a -> Std::I64`

`f(fold(l, r))`が真になる最大の`r`を、木の上の二分探索で求める

制約：0 <= l <= n、`f(unit)`が真、`f`は単調（区間を右に伸ばして偽になったら、さらに伸ばしても真にならない）

計算量：O(log n)。`f`の呼び出しもO(log n)回。

##### Parameters

- `l` : 区間の左端 (0-indexed)
- `f` : 区間の畳み込みについての条件
- `tree` : セグメント木

##### Examples

```fix
// 区間への加算と、区間の最大値の取得ができるセグメント木
let tree = build([1, 2, 5, 4], minimum, |(x, y)| max(x, y), 0, |(a, b)| a + b, |(a, x)| x + a);
let tree = tree.act_range(0, 2, 2); // [3, 4, 5, 4]
// 区間[0, 2)の最大値は4、区間[0, 3)の最大値は5
assert_eq(|_|"", tree.calc_max_right(0, |x| x <= 4), 2)
```

#### calc_min_left

Type: `Std::I64 -> (m -> Std::Bool) -> CPLib.LDSegtree::LDSegtree m a -> Std::I64`

`f(fold(l, r))`が真になる最小の`l`を、木の上の二分探索で求める

制約：0 <= r <= n、`f(unit)`が真、`f`は単調（区間を左に伸ばして偽になったら、さらに伸ばしても真にならない）

計算量：O(log n)。`f`の呼び出しもO(log n)回。

##### Parameters

- `r` : 区間の右端 (0-indexed, exclusive)
- `f` : 区間の畳み込みについての条件
- `tree` : セグメント木

##### Examples

```fix
// 区間への加算と、区間の最大値の取得ができるセグメント木
let tree = build([1, 2, 5, 4], minimum, |(x, y)| max(x, y), 0, |(a, b)| a + b, |(a, x)| x + a);
let tree = tree.act_range(0, 2, 2); // [3, 4, 5, 4]
// 区間[3, 4)の最大値は4、区間[2, 4)の最大値は5
assert_eq(|_|"", tree.calc_min_left(4, |x| x <= 4), 3)
```

#### create

Type: `Std::I64 -> m -> ((m, m) -> m) -> a -> ((a, a) -> a) -> ((a, m) -> m) -> CPLib.LDSegtree::LDSegtree m a`

すべての要素が単位元であるような遅延伝搬セグメント木を作成する

計算量：O(n)

##### Parameters

- `n` : セグメント木の要素数
- `unit` : 値モノイドの単位元
- `op` : 値モノイドの演算子
- `act_unit` : 作用モノイドの単位元
- `act_op` : 作用モノイドの演算子
- `act` : 右作用

#### fold

Type: `Std::I64 -> Std::I64 -> CPLib.LDSegtree::LDSegtree m a -> m`

半開区間[l, r)にある要素の畳み込みを計算する

制約：0 <= l <= r <= n

計算量：O(log n)

##### Parameters

- `l` : 区間の左端 (0-indexed)
- `r` : 区間の右端 (0-indexed, exclusive)
- `tree` : セグメント木

#### fold_all

Type: `CPLib.LDSegtree::LDSegtree m a -> m`

すべての要素の畳み込みを計算する

計算量：O(log n)

##### Parameters

- `tree` : セグメント木

#### init

**Deprecated**: Use `CPLib.LDSegtree::create` instead.

Type: `Std::I64 -> m -> ((m, m) -> m) -> a -> ((a, a) -> a) -> ((a, m) -> m) -> CPLib.LDSegtree::LDSegtree m a`

`create`の別名（非推奨）

#### set

Type: `Std::I64 -> m -> CPLib.LDSegtree::LDSegtree m a -> CPLib.LDSegtree::LDSegtree m a`

セグメント木の要素を設定する

制約：0 <= i < n

計算量：O(log n)

##### Parameters

- `i` : インデックス（0-indexed）
- `value` : 設定する値
- `tree` : セグメント木

## Types and aliases

### namespace CPLib.LDSegtree

#### LDSegtree

Defined as: `type LDSegtree m a = unbox struct { ...fields... }`

遅延伝搬セグメント木の型。

パラメータ`m`は「値」となるモノイドの型、`a`は「右作用」するモノイドの型。

## Traits and aliases

## Trait implementations