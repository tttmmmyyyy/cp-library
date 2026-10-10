# CPLib.LDSegtree

Defined in cp-library@0.14.0

モノイド構造および作用が動的に決められる遅延伝搬セグメント木

コンストラクタでモノイドおよび作用を指定する点以外は、`CPLib.LSegtree`と同じです。
モノイド構造・作用が静的に決まる場合は`CPLib.LSegtree`の方が高速です。

制約・計算量の n は要素数です。計算量は`op`, `act_op`, `act`がO(1)で動くとしたものです。

制約：作用は次を満たす（`x`, `y`は値、`a`, `b`は作用）
- act(x, act_unit) = x
- act(op(x, y), a) = op(act(x, a), act(y, a))
- act(x, act_op(a, b)) = act(act(x, a), b)

## Examples

```fix
// 区間への加算と、区間の最大値の取得ができるセグメント木
let tree = build(
    [1, 2, 3],
    minimum, |(x, y)| max(x, y), // 値モノイド：最大値
    0, |(a, b)| a + b,                // 作用モノイド：加法
    |(x, a)| x + a                    // 作用：加算
);
let tree = tree.act_range(0, 2, 10); // [11, 12, 3]
let (_, res) = tree.fold(1, 3);
assert_eq(|_|"", res, 12)
```

## Values

### namespace CPLib.LDSegtree

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

Type: `Std::Array m -> m -> ((m, m) -> m) -> a -> ((a, a) -> a) -> ((m, a) -> m) -> CPLib.LDSegtree::LDSegtree m a`

要素の配列からセグメント木を作成する

計算量：O(n)

##### Parameters

- `elems` : セグメント木の要素を格納する配列
- `unit` : 値モノイドの単位元
- `op` : 値モノイドの演算子
- `act_unit` : 作用モノイドの単位元
- `act_op` : 作用モノイドの演算子
- `act` : 右作用

#### fold

Type: `Std::I64 -> Std::I64 -> CPLib.LDSegtree::LDSegtree m a -> (CPLib.LDSegtree::LDSegtree m a, m)`

半開区間[l, r)にある要素の畳み込みを計算する

遅延作用の伝搬が行われるので、ツリー自体も更新される。

制約：0 <= l <= r <= n

計算量：O(log n)

##### Parameters

- `l` : 区間の左端 (0-indexed)
- `r` : 区間の右端 (0-indexed, exclusive)
- `tree` : セグメント木

#### init

Type: `Std::I64 -> m -> ((m, m) -> m) -> a -> ((a, a) -> a) -> ((m, a) -> m) -> CPLib.LDSegtree::LDSegtree m a`

すべての要素が単位元であるような遅延伝搬セグメント木を作成する

計算量：O(n)

##### Parameters

- `n` : セグメント木の要素数
- `unit` : 値モノイドの単位元
- `op` : 値モノイドの演算子
- `act_unit` : 作用モノイドの単位元
- `act_op` : 作用モノイドの演算子
- `act` : 右作用

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

##### field `n`

Type: `Std::I64`

要素数

##### field `unit`

Type: `m`

値モノイドの単位元

##### field `op`

Type: `(m, m) -> m`

値モノイドの演算子

##### field `act_unit`

Type: `a`

作用モノイドの単位元

##### field `act_op`

Type: `(a, a) -> a`

作用モノイドの演算子

##### field `act`

Type: `(m, a) -> m`

右作用

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