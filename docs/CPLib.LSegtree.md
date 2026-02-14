# CPLib.LSegtree

Defined in cp-library@0.9.0

遅延伝番セグメント木（右作用）

ある要素の値を取得する関数`@`はないので、もし必要なら`fold(i, i+1)`を使うこと。

使用例
```
// 最大値モノイド
type I64Max = struct { v : I64 };
namespace I64Max {
    make : I64 -> I64Max;
    make = |v| I64Max { v : v };
}
impl I64Max : Monoid {
    unit = make(I64::minimum);
    op = |lhs, rhs| make $ lhs.@v.max(rhs.@v);
}

// 加法モノイド
type I64Add = struct { v : I64 };
namespace I64Add {
    make : I64 -> I64Add;
    make = |v| I64Add { v : v };
}
impl I64Add : Monoid {
    unit = make(0);
    op = |lhs, rhs| make $ lhs.@v + rhs.@v;
}

// 加法モノイドの最大値モノイドに対する作用
impl I64Add : Action {
    type Set I64Add = I64Max; // 作用を受ける集合の型
    act = |a, x| I64Max::make(x.@v + a.@v);
}

main : IO ();
main = (
    let tree = LSegtree::init(3) : LSegtree I64Max I64Add;
    let tree = tree.set(0, I64Max::make(1));
    let tree = tree.set(1, I64Max::make(2));
    let tree = tree.set(2, I64Max::make(3));
    let (tree, res) = tree.fold(0, 3); // res.@v == 3
    let tree = tree.set(1, I64Max::make(3)); // [1, 3, 3]
    let tree = tree.act_range(0, 2, I64Add::make(1)); // [2, 4, 4]
    let (tree, res) = tree.fold(0, 2); // res.@v == 4
    pure()
);
```

## Values

### namespace CPLib.LSegtree

#### act_range

Type: `[a : CPLib.Trait::Action, a : CPLib.Trait::Monoid, m : CPLib.Trait::Monoid, CPLib.Trait::Action::Set a = m] Std::I64 -> Std::I64 -> a -> CPLib.LSegtree::LSegtree m a -> CPLib.LSegtree::LSegtree m a`

半開区間[l, r)に右から作用を適用する

##### Parameters

- `l` : 区間の左端 (0-indexed)
- `r` : 区間の右端 (0-indexed, exclusive)
- `a` : 適用する作用
- `tree` : セグメント木

#### build

Type: `[a : CPLib.Trait::Monoid, m : CPLib.Trait::Monoid] Std::Array m -> CPLib.LSegtree::LSegtree m a`

要素の配列からセグメント木を作成する

##### Parameters

- `elems` : セグメント木の要素を格納する配列

#### fold

Type: `[a : CPLib.Trait::Action, a : CPLib.Trait::Monoid, m : CPLib.Trait::Monoid, CPLib.Trait::Action::Set a = m] Std::I64 -> Std::I64 -> CPLib.LSegtree::LSegtree m a -> (CPLib.LSegtree::LSegtree m a, m)`

半開区間[l, r)にある要素の畳み込みを計算する

遅延作用の伝搬が行われるので、ツリー自体も更新される。

##### Parameters

- `l` : 区間の左端 (0-indexed)
- `r` : 区間の右端 (0-indexed, exclusive)
- `tree` : セグメント木

#### init

Type: `[a : CPLib.Trait::Monoid, m : CPLib.Trait::Monoid] Std::I64 -> CPLib.LSegtree::LSegtree m a`

すべての要素が単位元であるような遅延伝搬セグメント木を作成する

##### Parameters

- `n` : セグメント木の要素数

#### set

Type: `[a : CPLib.Trait::Action, a : CPLib.Trait::Monoid, m : CPLib.Trait::Monoid, CPLib.Trait::Action::Set a = m] Std::I64 -> m -> CPLib.LSegtree::LSegtree m a -> CPLib.LSegtree::LSegtree m a`

セグメント木の要素を設定する

##### Parameters

- `i` : インデックス（0-indexed）
- `value` : 設定する値
- `tree` : セグメント木

## Types and aliases

### namespace CPLib.LSegtree

#### LSegtree

Defined as: `type LSegtree m a = unbox struct { ...fields... }`

遅延伝搬セグメント木の型。

パラメータ`m`は「値」となるモノイドの型、`a`は「右作用」するモノイドの型。

##### field `n`

Type: `Std::I64`

要素数

##### field `elems`

Type: `Std::Array m`

値の配列

1-indexedで運用する：長さは`2n`、第0インデックスは使用しない。

##### field `lazy`

Type: `Std::Array a`

遅延されている作用の配列

1-indexedで運用する：長さは`2n`、第0インデックスは使用しない。

## Traits and aliases

## Trait implementations