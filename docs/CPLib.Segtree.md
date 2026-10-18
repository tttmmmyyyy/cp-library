# CPLib.Segtree

Defined in cp-library@0.15.0

セグメント木の実装

使用方法：
要素は`CPLib.Trait.Monoid`を実装している必要があります。
和・積・最小値・最大値のモノイドは`CPLib.Monoid`にあります。
それ以外のモノイドは、自分で型を作成し、`Monoid`を実装してください。
あとは、`create`や`build`を使ってセグメント木を作成し、
`@`で要素を取得、`set`で要素を更新、`fold`で区間の畳み込みを計算できます。
`fold_all`は全体の畳み込みを、`calc_max_right`と`calc_min_left`は区間の畳み込みが条件を満たす端を計算します。
```fix
import CPLib.Segtree;
import CPLib.Trait;

// 文字列の結合に関するモノイド
type StrConcat = struct { v : String };
namespace StrConcat {
    make : String -> StrConcat = |v| StrConcat { v };
}
impl StrConcat : Monoid {
    unit = make("");
    op = |lhs, rhs| make $ lhs.@v + rhs.@v;
}

main : IO () = (
    let tree = build(["a", "x", "c"].map(make));
    let tree = tree.set(1, make("b"));
    assert_eq(|_|"", tree.@(1).@v, "b");;
    assert_eq(|_|"", tree.fold(0, 3).@v, "abc")
);
```

制約・計算量の n は要素数です。計算量は`op`がO(1)で動くとしたものです。

モノイド構造が動的に決まる場合は、モジュール`CPLib.DSegtree`を使用してください。

## Values

### namespace CPLib.Segtree

#### @

Type: `Std::I64 -> CPLib.Segtree::Segtree m -> m`

セグメント木の要素を取得する

制約：0 <= i < n

計算量：O(1)

##### Parameters

- `i` : インデックス（0-indexed）
- `tree` : セグメント木

#### @size

Type: `CPLib.Segtree::Segtree m -> Std::I64`

セグメント木の要素数を取得する

計算量：O(1)

##### Parameters

- `tree` : セグメント木

#### build

Type: `[m : CPLib.Trait::Monoid] Std::Array m -> CPLib.Segtree::Segtree m`

要素の配列からセグメント木を作成する

計算量：O(n)

##### Parameters

- `elems` : セグメント木の要素を格納する配列

#### calc_max_right

Type: `[m : CPLib.Trait::Monoid] Std::I64 -> (m -> Std::Bool) -> CPLib.Segtree::Segtree m -> Std::I64`

`f(fold(l, r))`が真になる最大の`r`を、木の上の二分探索で求める

制約：0 <= l <= n、`f(unit)`が真、`f`は単調（区間を右に伸ばして偽になったら、さらに伸ばしても真にならない）

計算量：O(log n)。`f`の呼び出しもO(log n)回。

##### Parameters

- `l` : 区間の左端 (0-indexed)
- `f` : 区間の畳み込みについての条件
- `tree` : セグメント木

##### Examples

```fix
import CPLib.Segtree;
import CPLib.Trait;

// 加法モノイド
type Sum = struct { v : I64 };
impl Sum : Monoid {
    unit = Sum { v : 0 };
    op = |lhs, rhs| Sum { v : lhs.@v + rhs.@v };
}

main : IO () = (
    let tree = build([1, 2, 3, 4].map(|v| Sum { v }));
    // 区間[0, 3)の和は6、区間[0, 4)の和は10
    assert_eq(|_|"", tree.calc_max_right(0, |s| s.@v <= 6), 3)
);
```

#### calc_min_left

Type: `[m : CPLib.Trait::Monoid] Std::I64 -> (m -> Std::Bool) -> CPLib.Segtree::Segtree m -> Std::I64`

`f(fold(l, r))`が真になる最小の`l`を、木の上の二分探索で求める

制約：0 <= r <= n、`f(unit)`が真、`f`は単調（区間を左に伸ばして偽になったら、さらに伸ばしても真にならない）

計算量：O(log n)。`f`の呼び出しもO(log n)回。

##### Parameters

- `r` : 区間の右端 (0-indexed, exclusive)
- `f` : 区間の畳み込みについての条件
- `tree` : セグメント木

##### Examples

```fix
import CPLib.Segtree;
import CPLib.Trait;

// 加法モノイド
type Sum = struct { v : I64 };
impl Sum : Monoid {
    unit = Sum { v : 0 };
    op = |lhs, rhs| Sum { v : lhs.@v + rhs.@v };
}

main : IO () = (
    let tree = build([1, 2, 3, 4].map(|v| Sum { v }));
    // 区間[2, 4)の和は7、区間[1, 4)の和は9
    assert_eq(|_|"", tree.calc_min_left(4, |s| s.@v <= 7), 2)
);
```

#### create

Type: `[m : CPLib.Trait::Monoid] Std::I64 -> CPLib.Segtree::Segtree m`

すべての要素が単位元であるようなセグメント木を作成する

計算量：O(n)

##### Parameters

- `n` : セグメント木の要素数

#### fold

Type: `[m : CPLib.Trait::Monoid] Std::I64 -> Std::I64 -> CPLib.Segtree::Segtree m -> m`

半開区間[l, r)にある要素の畳み込みを計算する

制約：0 <= l <= r <= n

計算量：O(log n)

##### Parameters

- `l` : 区間の左端 (0-indexed)
- `r` : 区間の右端 (0-indexed, exclusive)
- `tree` : セグメント木

#### fold_all

Type: `[m : CPLib.Trait::Monoid] CPLib.Segtree::Segtree m -> m`

すべての要素の畳み込みを計算する

計算量：O(log n)

##### Parameters

- `tree` : セグメント木

#### init

**Deprecated**: Use `CPLib.Segtree::create` instead.

Type: `[m : CPLib.Trait::Monoid] Std::I64 -> CPLib.Segtree::Segtree m`

`create`の別名（非推奨）

#### set

Type: `[m : CPLib.Trait::Monoid] Std::I64 -> m -> CPLib.Segtree::Segtree m -> CPLib.Segtree::Segtree m`

要素を設定する

制約：0 <= i < n

計算量：O(log n)

##### Parameters

- `i` : インデックス（0-indexed）
- `value` : 設定する値
- `tree` : セグメント木

## Types and aliases

### namespace CPLib.Segtree

#### Segtree

Defined as: `type Segtree m = unbox struct { ...fields... }`

セグメント木

## Traits and aliases

## Trait implementations