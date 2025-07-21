# CPLib.Segtree

Defined in cp-library@0.1.0

セグメント木の実装

使用方法：
要素は`CPLib.Trait.Monoid`を実装している必要があります。
先ずはwrapper型を作成し、`Monoid`を実装してください：
```
// 文字列の結合に関するモノイド
type StrConcat = struct { v : String };
namespace StrConcat {
    make : String -> StrConcat;
    make = |v| StrConcat { v : v };
}
impl StrConcat : Monoid {
    unit = make("");
    op = |lhs, rhs| make $ lhs.@v + rhs.@v;
}
```
あとは、`make_unit`や`make`を使ってセグメント木を作成し、
`@`で要素を取得、`set`で要素を更新、`fold`で区間の畳み込みを計算できます。
```
let tree = Segtree::make(["a", "x", "c"].map(StrConcat::make));
let tree = tree.set(1, make("b"));
assert_eq(|_|"", tree.@(1), make("b"));;
assert_eq(|_|"", tree.fold(0, 3), make("abc"));;
```

## Values

### namespace CPLib.Segtree

#### @

Type: `Std::I64 -> CPLib.Segtree::Segtree m -> m`

セグメント木の要素を取得する

##### Parameters

- `i` : インデックス（0-indexed）
- `tree` : セグメント木

#### fold

Type: `[m : CPLib.Trait::Monoid] Std::I64 -> Std::I64 -> CPLib.Segtree::Segtree m -> m`

半開区間[l, r)にある要素の畳み込みを計算する

##### Parameters

- `l` : 区間の左端 (0-indexed)
- `r` : 区間の右端 (0-indexed, exclusive)

#### make

Type: `[m : CPLib.Trait::Monoid] Std::Array m -> CPLib.Segtree::Segtree m`

セグメント木を作成する

##### Parameters

- `elems` : セグメント木の要素を格納する配列

#### make_unit

Type: `[m : CPLib.Trait::Monoid] Std::I64 -> CPLib.Segtree::Segtree m`

すべての要素が単位元であるようなセグメント木を作成する

##### Parameters

- `n` : セグメント木の要素数

#### set

Type: `[m : CPLib.Trait::Monoid] Std::I64 -> m -> CPLib.Segtree::Segtree m -> CPLib.Segtree::Segtree m`

要素を設定する

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