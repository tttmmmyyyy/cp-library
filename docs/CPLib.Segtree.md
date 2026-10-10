# CPLib.Segtree

Defined in cp-library@0.15.0

セグメント木の実装

使用方法：
要素は`CPLib.Trait.Monoid`を実装している必要があります。
先ずはwrapper型を作成し、`Monoid`を実装してください。
あとは、`init`や`build`を使ってセグメント木を作成し、
`@`で要素を取得、`set`で要素を更新、`fold`で区間の畳み込みを計算できます。
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

#### build

Type: `[m : CPLib.Trait::Monoid] Std::Array m -> CPLib.Segtree::Segtree m`

要素の配列からセグメント木を作成する

計算量：O(n)

##### Parameters

- `elems` : セグメント木の要素を格納する配列

#### fold

Type: `[m : CPLib.Trait::Monoid] Std::I64 -> Std::I64 -> CPLib.Segtree::Segtree m -> m`

半開区間[l, r)にある要素の畳み込みを計算する

制約：0 <= l <= r <= n

計算量：O(log n)

##### Parameters

- `l` : 区間の左端 (0-indexed)
- `r` : 区間の右端 (0-indexed, exclusive)
- `tree` : セグメント木

#### init

Type: `[m : CPLib.Trait::Monoid] Std::I64 -> CPLib.Segtree::Segtree m`

すべての要素が単位元であるようなセグメント木を作成する

計算量：O(n)

##### Parameters

- `n` : セグメント木の要素数

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

##### field `n`

Type: `Std::I64`

要素数

##### field `elems`

Type: `Std::Array m`

内部配列

1-indexedで運用する：長さは`2n`、第0インデックスは使用しない。

## Traits and aliases

## Trait implementations