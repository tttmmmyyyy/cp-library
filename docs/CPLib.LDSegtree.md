# CPLib.LDSegtree

Defined in cp-library@0.5.3

モノイド構造および作用が動的に決められる遅延伝搬セグメント木

コンストラクタでモノイドおよび作用を指定する点以外は、`CPLib.LSegtree`と同じです。
モノイド構造・作用が静的に決まる場合は`CPLib.LSegtree`の方が高速です。

## Values

### namespace CPLib.LDSegtree

#### act_range

Type: `Std::I64 -> Std::I64 -> a -> CPLib.LDSegtree::LDSegtree m a -> CPLib.LDSegtree::LDSegtree m a`

半開区間[l, r)に右から作用を適用する

##### Parameters

- `l` : 区間の左端 (0-indexed)
- `r` : 区間の右端 (0-indexed, exclusive)
- `a` : 適用する作用
- `tree` : セグメント木

#### build

Type: `Std::Array m -> m -> ((m, m) -> m) -> a -> ((a, a) -> a) -> ((m, a) -> m) -> CPLib.LDSegtree::LDSegtree m a`

要素の配列からセグメント木を作成する

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

##### Parameters

- `l` : 区間の左端 (0-indexed)
- `r` : 区間の右端 (0-indexed, exclusive)
- `tree` : セグメント木

#### init

Type: `Std::I64 -> m -> ((m, m) -> m) -> a -> ((a, a) -> a) -> ((m, a) -> m) -> CPLib.LDSegtree::LDSegtree m a`

すべての要素が単位元であるような遅延伝搬セグメント木を作成する

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