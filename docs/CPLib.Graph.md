# CPLib.Graph

Defined in cp-library@0.15.0

グラフの表現と基本的なアルゴリズム

制約・計算量の n は頂点数、m は辺数を表します。

## Examples

```fix
// 辺のデータをコストとして、ダイクストラ法で最短距離を求める
let g = create(3).add_edge(0, 1, 5).add_edge(1, 2, 2).add_edge(0, 2, 10);
assert_eq(|_|"", g.dijkstra(0), [0, 5, 7])
```

## Values

### namespace CPLib.Graph

#### add_edge

Type: `Std::I64 -> Std::I64 -> c -> CPLib.Graph::Graph c -> CPLib.Graph::Graph c`

グラフに辺を追加する

制約：0 <= from, to < n

計算量：ならしO(1)

##### Parameters

- `from` : 始点の頂点番号
- `to` : 終点の頂点番号
- `data` : 辺のデータ
- `graph` : グラフ

#### add_edge_id

Type: `Std::I64 -> Std::I64 -> c -> CPLib.Graph::Graph c -> (CPLib.Graph::Graph c, CPLib.Graph::EdgeId)`

グラフに辺を追加する（辺IDを返す）

制約：0 <= from, to < n

計算量：ならしO(1)

##### Parameters

- `from` : 始点の頂点番号
- `to` : 終点の頂点番号
- `data` : 辺のデータ
- `graph` : グラフ

#### bellman_ford

Type: `[c : CPLib.Trait::Inf, c : Std::Additive, c : Std::Eq, c : Std::LessThan] Std::I64 -> CPLib.Graph::Graph c -> Std::Array c`

ベルマンフォード法：グラフと開始ノードが与えられたとき、開始ノードから各ノードに到達するまでの最小コストの配列を返す。

到達できないノードまでの距離には`Inf::inf`が設定されます。

制約：0 <= start < n, 開始ノードから到達できる負の閉路がない

計算量：O(n (n + m))

##### Parameters

- `start` : 開始ノードの番号
- `graph` : グラフ

#### calc_sccs

Type: `CPLib.Graph::Graph c -> Std::Array (Std::Array Std::I64)`

グラフの強連結成分分解を求める

戻り値は、各強連結成分を構成する頂点のリストの配列です。
また、戻り値はトポロジカルソートされています：uとvが異なる強連結成分cu, cvに属するとき、uからvに到達できるなら、cuはcvの前に現れます。

計算量：O(n + m)

##### Parameters

- `graph` : グラフ

#### create

Type: `Std::I64 -> CPLib.Graph::Graph c`

辺のないグラフを作成する

計算量：O(n)

##### Parameters

- `n` : 頂点数

#### dijkstra

Type: `[c : CPLib.Trait::Inf, c : Std::Additive, c : Std::LessThan] Std::I64 -> CPLib.Graph::Graph c -> Std::Array c`

ダイクストラ法：グラフと開始ノードが与えられたとき、開始ノードから各ノードに到達するまでの最小コストの配列を返す。

到達できないノードまでの距離には`Inf::inf`が設定されます。

制約：0 <= start < n, 辺のコスト >= 0

計算量：O((n + m) log m)

##### Parameters

- `start` : 開始ノードの番号
- `graph` : グラフ

#### get_edge

Type: `CPLib.Graph::EdgeId -> CPLib.Graph::Graph c -> CPLib.Graph::Edge c`

辺を取得する

計算量：O(1)

##### Parameters

- `edge_id` : 辺の識別子
- `graph` : グラフ

#### get_size

Type: `CPLib.Graph::Graph c -> Std::I64`

グラフの頂点数を取得する

計算量：O(1)

##### Parameters

- `graph` : グラフ

### namespace CPLib.Graph::Edge

#### make

Type: `Std::I64 -> c -> CPLib.Graph::Edge c`

辺を作成する

### namespace CPLib.Graph::NodeDistance

#### make

Type: `Std::I64 -> c -> CPLib.Graph::NodeDistance c`

## Types and aliases

### namespace CPLib.Graph

#### Edge

Defined as: `type Edge c = unbox struct { ...fields... }`

グラフの辺を表す型（始点番号はなし）

##### field `to`

Type: `Std::I64`

終点の頂点番号

##### field `data`

Type: `c`

辺のデータ

#### EdgeId

Defined as: `type EdgeId = unbox struct { ...fields... }`

辺の識別子の型

##### field `from`

Type: `Std::I64`

始点インデックス

##### field `idx`

Type: `Std::I64`

辺インデックス

#### Graph

Defined as: `type Graph c = unbox struct { ...fields... }`

グラフの隣接リストによる表現

型パラメータ`c`は辺に付随するデータの型です（例：ダイクストラ法に使うときはコスト）。不要な場合はユニット型`()`や自分で作ったempty typeなどを指定するとメモリの節約になります。

##### field `edges`

Type: `Std::Array (Std::Array (CPLib.Graph::Edge c))`

`edges.@(s)` は頂点`s`から出る辺のリストです。

#### NodeDistance

Defined as: `type NodeDistance c = unbox struct { ...fields... }`

ノードとその距離を表す型（ダイクストラ法などで使用）

##### field `node`

Type: `Std::I64`

##### field `dist`

Type: `c`

## Traits and aliases

## Trait implementations

### impl `[c : Std::LessThan] CPLib.Graph::NodeDistance c : Std::LessThan`