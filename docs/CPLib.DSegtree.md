# CPLib.DSegtree

Defined in cp-library@0.15.0

モノイド構造が動的に決まる際に使えるセグメント木。

コンストラクタでモノイド（unitおよびop）を指定する点以外は、`CPLib.Segtree`と同じです。
モノイド構造が静的に決まる場合は`CPLib.Segtree`の方が高速です。

制約・計算量の n は要素数です。計算量は`op`がO(1)で動くとしたものです。

## Examples

```fix
// 区間の最小値を求めるセグメント木
let tree = build([5, 3, 8], maximum, |(x, y)| min(x, y));
let tree = tree.set(1, 9); // [5, 9, 8]
assert_eq(|_|"", tree.fold(1, 3), 8)
```

## Values

### namespace CPLib.DSegtree

#### @

Type: `Std::I64 -> CPLib.DSegtree::DSegtree m -> m`

セグメント木の要素を取得する

制約：0 <= i < n

計算量：O(1)

##### Parameters

- `i` : インデックス（0-indexed）
- `tree` : セグメント木

#### @size

Type: `CPLib.DSegtree::DSegtree m -> Std::I64`

セグメント木の要素数を取得する

計算量：O(1)

##### Parameters

- `tree` : セグメント木

#### build

Type: `Std::Array m -> m -> ((m, m) -> m) -> CPLib.DSegtree::DSegtree m`

要素の配列からセグメント木を作成する

計算量：O(n)

##### Parameters

- `elems` : セグメント木の要素を格納する配列
- `unit` : モノイドの単位元
- `op` : モノイドの演算子

#### calc_max_right

Type: `Std::I64 -> (m -> Std::Bool) -> CPLib.DSegtree::DSegtree m -> Std::I64`

`f(fold(l, r))`が真になる最大の`r`を、木の上の二分探索で求める

制約：0 <= l <= n、`f(unit)`が真、`f`は単調（区間を右に伸ばして偽になったら、さらに伸ばしても真にならない）

計算量：O(log n)。`f`の呼び出しもO(log n)回。

##### Parameters

- `l` : 区間の左端 (0-indexed)
- `f` : 区間の畳み込みについての条件
- `tree` : セグメント木

##### Examples

```fix
let tree = build([1, 2, 3, 4], 0, |(x, y)| x + y);
// 区間[0, 3)の和は6、区間[0, 4)の和は10
assert_eq(|_|"", tree.calc_max_right(0, |s| s <= 6), 3)
```

#### calc_min_left

Type: `Std::I64 -> (m -> Std::Bool) -> CPLib.DSegtree::DSegtree m -> Std::I64`

`f(fold(l, r))`が真になる最小の`l`を、木の上の二分探索で求める

制約：0 <= r <= n、`f(unit)`が真、`f`は単調（区間を左に伸ばして偽になったら、さらに伸ばしても真にならない）

計算量：O(log n)。`f`の呼び出しもO(log n)回。

##### Parameters

- `r` : 区間の右端 (0-indexed, exclusive)
- `f` : 区間の畳み込みについての条件
- `tree` : セグメント木

##### Examples

```fix
let tree = build([1, 2, 3, 4], 0, |(x, y)| x + y);
// 区間[2, 4)の和は7、区間[1, 4)の和は9
assert_eq(|_|"", tree.calc_min_left(4, |s| s <= 7), 2)
```

#### create

Type: `Std::I64 -> m -> ((m, m) -> m) -> CPLib.DSegtree::DSegtree m`

すべての要素が単位元であるようなセグメント木を作成する

計算量：O(n)

##### Parameters

- `n` : セグメント木の要素数
- `unit` : モノイドの単位元
- `op` : モノイドの演算子

#### fold

Type: `Std::I64 -> Std::I64 -> CPLib.DSegtree::DSegtree m -> m`

半開区間[l, r)にある要素の畳み込みを計算する

制約：0 <= l <= r <= n

計算量：O(log n)

##### Parameters

- `l` : 区間の左端 (0-indexed)
- `r` : 区間の右端 (0-indexed, exclusive)
- `tree` : セグメント木

#### fold_all

Type: `CPLib.DSegtree::DSegtree m -> m`

すべての要素の畳み込みを計算する

計算量：O(log n)

##### Parameters

- `tree` : セグメント木

#### init

**Deprecated**: Use `CPLib.DSegtree::create` instead.

Type: `Std::I64 -> m -> ((m, m) -> m) -> CPLib.DSegtree::DSegtree m`

`create`の別名（非推奨）

#### set

Type: `Std::I64 -> m -> CPLib.DSegtree::DSegtree m -> CPLib.DSegtree::DSegtree m`

要素を設定する

制約：0 <= i < n

計算量：O(log n)

##### Parameters

- `i` : インデックス（0-indexed）
- `value` : 設定する値
- `tree` : セグメント木

## Types and aliases

### namespace CPLib.DSegtree

#### DSegtree

Defined as: `type DSegtree m = unbox struct { ...fields... }`

セグメント木

## Traits and aliases

## Trait implementations