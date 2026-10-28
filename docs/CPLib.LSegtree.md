# CPLib.LSegtree

Defined in cp-library@0.15.3

遅延伝搬セグメント木（右作用）

制約・計算量の n は要素数です。計算量は各モノイドの`op`と`act`がO(1)で動くとしたものです。

制約：作用は次を満たす（`a`, `b`は作用、`x`, `y`は値）
- act(unit, x) = x
- act(a, op(x, y)) = op(act(a, x), act(a, y))
- act(op(a, b), x) = act(b, act(a, x))

和（`Sum`、`WeightedSum`）・最小値・最大値のモノイドと、区間加算・区間乗算・区間代入・アフィン変換の作用は`CPLib.Monoid`にあります。
それ以外のモノイドと作用は、次の例のように型を作成し、`Monoid`と`Action`を実装してください。

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
    assert_eq(|_|"", tree.fold(0, 3).@v, 3);;
    let tree = tree.set(1, make(3)); // [1, 3, 3]
    let tree = tree.act_range(0, 2, make(1)); // [2, 4, 3]
    assert_eq(|_|"", tree.fold(0, 2).@v, 4)
);
```

## Values

### namespace CPLib.LSegtree

#### @

Type: `[a : CPLib.Trait::Action, a : CPLib.Trait::Monoid, m : CPLib.Trait::Monoid, CPLib.Trait::Action::Set a = m] Std::I64 -> CPLib.LSegtree::LSegtree m a -> m`

セグメント木の要素を取得する

制約：0 <= i < n

計算量：O(log n)

##### Parameters

- `i` : インデックス（0-indexed）
- `tree` : セグメント木

#### @size

Type: `CPLib.LSegtree::LSegtree m a -> Std::I64`

セグメント木の要素数を取得する

計算量：O(1)

##### Parameters

- `tree` : セグメント木

#### act_at

Type: `[a : CPLib.Trait::Action, a : CPLib.Trait::Monoid, m : CPLib.Trait::Monoid, CPLib.Trait::Action::Set a = m] Std::I64 -> a -> CPLib.LSegtree::LSegtree m a -> CPLib.LSegtree::LSegtree m a`

1つの要素に作用を適用する

`act_range(i, i + 1, a)`と同じ結果になる。

制約：0 <= i < n

計算量：O(log n)

##### Parameters

- `i` : インデックス（0-indexed）
- `a` : 作用
- `tree` : セグメント木

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

#### calc_max_right

Type: `[a : CPLib.Trait::Action, a : CPLib.Trait::Monoid, m : CPLib.Trait::Monoid, CPLib.Trait::Action::Set a = m] Std::I64 -> (m -> Std::Bool) -> CPLib.LSegtree::LSegtree m a -> Std::I64`

`f(fold(l, r))`が真になる最大の`r`を、木の上の二分探索で求める

制約：0 <= l <= n、`f(unit)`が真、`f`は単調（区間を右に伸ばして偽になったら、さらに伸ばしても真にならない）

計算量：O(log n)。`f`の呼び出しもO(log n)回。

##### Parameters

- `l` : 区間の左端 (0-indexed)
- `f` : 区間の畳み込みについての条件
- `tree` : セグメント木

##### Examples

```fix
// `I64Max`は最大値モノイド、`I64Add`はそれに加算で作用する加法モノイド（定義はモジュールの使用例と同じ）
let tree = build([1, 2, 5, 4].map(make)) : LSegtree I64Max I64Add;
let tree = tree.act_range(0, 2, make(2)); // [3, 4, 5, 4]
// 区間[0, 2)の最大値は4、区間[0, 3)の最大値は5
assert_eq(|_|"", tree.calc_max_right(0, |x| x.@v <= 4), 2)
```

#### calc_min_left

Type: `[a : CPLib.Trait::Action, a : CPLib.Trait::Monoid, m : CPLib.Trait::Monoid, CPLib.Trait::Action::Set a = m] Std::I64 -> (m -> Std::Bool) -> CPLib.LSegtree::LSegtree m a -> Std::I64`

`f(fold(l, r))`が真になる最小の`l`を、木の上の二分探索で求める

制約：0 <= r <= n、`f(unit)`が真、`f`は単調（区間を左に伸ばして偽になったら、さらに伸ばしても真にならない）

計算量：O(log n)。`f`の呼び出しもO(log n)回。

##### Parameters

- `r` : 区間の右端 (0-indexed, exclusive)
- `f` : 区間の畳み込みについての条件
- `tree` : セグメント木

##### Examples

```fix
// `I64Max`は最大値モノイド、`I64Add`はそれに加算で作用する加法モノイド（定義はモジュールの使用例と同じ）
let tree = build([1, 2, 5, 4].map(make)) : LSegtree I64Max I64Add;
let tree = tree.act_range(0, 2, make(2)); // [3, 4, 5, 4]
// 区間[3, 4)の最大値は4、区間[2, 4)の最大値は5
assert_eq(|_|"", tree.calc_min_left(4, |x| x.@v <= 4), 3)
```

#### create

Type: `[a : CPLib.Trait::Monoid, m : CPLib.Trait::Monoid] Std::I64 -> CPLib.LSegtree::LSegtree m a`

すべての要素が単位元であるような遅延伝搬セグメント木を作成する

計算量：O(n)

##### Parameters

- `n` : セグメント木の要素数

#### fold

Type: `[a : CPLib.Trait::Action, a : CPLib.Trait::Monoid, m : CPLib.Trait::Monoid, CPLib.Trait::Action::Set a = m] Std::I64 -> Std::I64 -> CPLib.LSegtree::LSegtree m a -> m`

半開区間[l, r)にある要素の畳み込みを計算する

制約：0 <= l <= r <= n

計算量：O(log n)

##### Parameters

- `l` : 区間の左端 (0-indexed)
- `r` : 区間の右端 (0-indexed, exclusive)
- `tree` : セグメント木

#### fold_all

Type: `[m : CPLib.Trait::Monoid] CPLib.LSegtree::LSegtree m a -> m`

すべての要素の畳み込みを計算する

計算量：O(log n)

##### Parameters

- `tree` : セグメント木

#### init

**Deprecated**: Use `CPLib.LSegtree::create` instead.

Type: `[a : CPLib.Trait::Monoid, m : CPLib.Trait::Monoid] Std::I64 -> CPLib.LSegtree::LSegtree m a`

`create`の別名（非推奨）

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

## Traits and aliases

## Trait implementations