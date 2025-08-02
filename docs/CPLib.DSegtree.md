# CPLib.DSegtree

Defined in cp-library@0.3.0

モノイド構造が動的に決まる際に使えるセグメント木。

コンストラクタでモノイド（unitおよびop）を指定する点以外は、`CPLib.Segtree`と同じです。
モノイド構造が静的に決まる場合は`CPLib.Segtree`の方が高速です。

## Values

### namespace CPLib.DSegtree

#### @

Type: `Std::I64 -> CPLib.DSegtree::DSegtree m -> m`

セグメント木の要素を取得する

##### Parameters

- `i` : インデックス（0-indexed）
- `tree` : セグメント木

#### build

Type: `Std::Array m -> m -> ((m, m) -> m) -> CPLib.DSegtree::DSegtree m`

セグメント木を作成する

##### Parameters

- `unit` : モノイドの単位元
- `op` : モノイドの演算子
- `elems` : セグメント木の要素を格納する配列

#### fold

Type: `Std::I64 -> Std::I64 -> CPLib.DSegtree::DSegtree m -> m`

半開区間[l, r)にある要素の畳み込みを計算する

##### Parameters

- `l` : 区間の左端 (0-indexed)
- `r` : 区間の右端 (0-indexed, exclusive)

#### init

Type: `Std::I64 -> m -> ((m, m) -> m) -> CPLib.DSegtree::DSegtree m`

すべての要素が単位元であるようなセグメント木を作成する

##### Parameters

- `unit` : モノイドの単位元
- `op` : モノイドの演算子
- `n` : セグメント木の要素数

#### set

Type: `Std::I64 -> m -> CPLib.DSegtree::DSegtree m -> CPLib.DSegtree::DSegtree m`

要素を設定する

##### Parameters

- `i` : インデックス（0-indexed）
- `value` : 設定する値
- `tree` : セグメント木

## Types and aliases

### namespace CPLib.DSegtree

#### DSegtree

Defined as: `type DSegtree m = unbox struct { ...fields... }`

セグメント木

##### field `n`

Type: `Std::I64`

要素数

##### field `unit`

Type: `m`

ユニット

##### field `op`

Type: `(m, m) -> m`

演算子

##### field `elems`

Type: `Std::Array m`

内部配列

1-indexedで運用する：長さは`2n`、第0インデックスは使用しない。

## Traits and aliases

## Trait implementations