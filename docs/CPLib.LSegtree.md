# CPLib.LSegtree

Defined in cp-library@0.14.0

遅延伝搬セグメント木（右作用）

ある要素の値を取得する関数`@`はないので、もし必要なら`fold(i, i+1)`を使うこと。

制約・計算量の n は要素数です。計算量は各モノイドの`op`と`act`がO(1)で動くとしたものです。

制約：作用は次を満たす（`a`, `b`は作用、`x`, `y`は値）
- act(unit, x) = x
- act(a, op(x, y)) = op(act(a, x), act(a, y))
- act(op(a, b), x) = act(b, act(a, x))

使用例
```fix
import CPLib.LSegtree;
import CPLib.Trait;

// 最大値モノイド
type I64Max = struct { v : I64 };
namespace I64Max {
    make : I64 -> I64Max = |v| I64Max { v };
}
impl I64Max : Monoid {
    unit = make(minimum);
    op = |lhs, rhs| make $ lhs.@v.max(rhs.@v);
}

// 加法モノイド
type I64Add = struct { v : I64 };
namespace I64Add {
    make : I64 -> I64Add = |v| I64Add { v };
}
impl I64Add : Monoid {
    unit = make(0);
    op = |lhs, rhs| make $ lhs.@v + rhs.@v;
}

// 加法モノイドの最大値モノイドに対する作用
impl I64Add : Action {
    type Set I64Add = I64Max; // 作用を受ける集合の型
    act = |a, x| make(x.@v + a.@v);
}

main : IO () = (
    let tree = build([1, 2, 3].map(make)) : LSegtree I64Max I64Add;
    let (tree, res) = tree.fold(0, 3);
    assert_eq(|_|"", res.@v, 3);;
    let tree = tree.set(1, make(3)); // [1, 3, 3]
    let tree = tree.act_range(0, 2, make(1)); // [2, 4, 3]
    let (_, res) = tree.fold(0, 2);
    assert_eq(|_|"", res.@v, 4)
);
```

## Values

### namespace CPLib.LSegtree

#### act_range

Type: `[a : CPLib.Trait::Action, a : CPLib.Trait::Monoid, m : CPLib.Trait::Monoid, CPLib.Trait::Action::Set a = m] Std::I64 -> Std::I64 -> a -> CPLib.LSegtree::LSegtree m a -> CPLib.LSegtree::LSegtree m a`

半開区間[l, r)に右から作用を適用する

制約：0 <= l <= r <= n

計算量：O(log n)

##### Parameters

- `l` : 区間の左端 (0-indexed)
- `r` : 区間の右端 (0-indexed, exclusive)
- `a` : 適用する作用
- `tree` : セグメント木

#### build

Type: `[a : CPLib.Trait::Monoid, m : CPLib.Trait::Monoid] Std::Array m -> CPLib.LSegtree::LSegtree m a`

要素の配列からセグメント木を作成する

計算量：O(n)

##### Parameters

- `elems` : セグメント木の要素を格納する配列

#### fold

Type: `[a : CPLib.Trait::Action, a : CPLib.Trait::Monoid, m : CPLib.Trait::Monoid, CPLib.Trait::Action::Set a = m] Std::I64 -> Std::I64 -> CPLib.LSegtree::LSegtree m a -> (CPLib.LSegtree::LSegtree m a, m)`

半開区間[l, r)にある要素の畳み込みを計算する

遅延作用の伝搬が行われるので、ツリー自体も更新される。

制約：0 <= l <= r <= n

計算量：O(log n)

##### Parameters

- `l` : 区間の左端 (0-indexed)
- `r` : 区間の右端 (0-indexed, exclusive)
- `tree` : セグメント木

#### init

Type: `[a : CPLib.Trait::Monoid, m : CPLib.Trait::Monoid] Std::I64 -> CPLib.LSegtree::LSegtree m a`

すべての要素が単位元であるような遅延伝搬セグメント木を作成する

計算量：O(n)

##### Parameters

- `n` : セグメント木の要素数

#### set

Type: `[a : CPLib.Trait::Action, a : CPLib.Trait::Monoid, m : CPLib.Trait::Monoid, CPLib.Trait::Action::Set a = m] Std::I64 -> m -> CPLib.LSegtree::LSegtree m a -> CPLib.LSegtree::LSegtree m a`

セグメント木の要素を設定する

制約：0 <= i < n

計算量：O(log n)

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