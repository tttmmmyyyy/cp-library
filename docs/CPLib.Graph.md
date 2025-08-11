# CPLib.Graph

Defined in cp-library@0.5.0

## Values

### namespace CPLib.Graph

#### add_edge

Type: `Std::I64 -> Std::I64 -> c -> CPLib.Graph::Graph c -> CPLib.Graph::Graph c`

グラフに辺を追加する

##### Parameters

- `from` : 始点の頂点番号
- `to` : 終点の頂点番号
- `data` : 辺のデータ
- `graph` : グラフ

#### add_edge_id

Type: `Std::I64 -> Std::I64 -> c -> CPLib.Graph::Graph c -> (CPLib.Graph::Graph c, CPLib.Graph::EdgeId)`

グラフに辺を追加する（辺IDを返す）

##### Parameters

- `from` : 始点の頂点番号
- `to` : 終点の頂点番号
- `data` : 辺のデータ
- `graph` : グラフ

#### bellman_ford

Type: `[c : Std::Additive, c : Std::LessThan, c : CPLib.Trait::Inf, c : Std::Eq] Std::I64 -> CPLib.Graph::Graph c -> Std::Array c`

ベルマンフォード法：グラフと開始ノードが与えられたとき、開始ノードから各ノードに到達するまでの最小コストの配列を返す。

到達できないノードまでの距離には`Inf::inf`が設定されます。

負の閉路が存在する場合は無限ループに陥ります。

##### Parameters

- `start` : 開始ノードの番号
- `graph` : グラフ

#### calc_sccs

Type: `CPLib.Graph::Graph c -> Std::Array (Std::Array Std::I64)`

グラフの強連結成分分解を求める

戻り値は、各強連結成分を構成する頂点のリストの配列です。
また、戻り値はトポロジカルソートされています：uとvが異なる強連結成分cu, cvに属するとき、uからvに到達できるなら、cuはcvの前に現れます。

##### Parameters

- `g` : グラフ

#### create

Type: `Std::I64 -> CPLib.Graph::Graph c`

離散的なグラフを作成する

##### Parameters

- `n` : 頂点数

#### dijkstra

Type: `[c : Std::Additive, c : Std::LessThan, c : CPLib.Trait::Inf] Std::I64 -> CPLib.Graph::Graph c -> Std::Array c`

ダイクストラ法：グラフと開始ノードが与えられたとき、開始ノードから各ノードに到達するまでの最小コストの配列を返す。

各辺のコストは非負である必要があります。

到達できないノードまでの距離には`Inf::inf`が設定されます。

##### Parameters

- `start` : 開始ノードの番号
- `graph` : グラフ

#### get_edge

Type: `CPLib.Graph::EdgeId -> CPLib.Graph::Graph c -> CPLib.Graph::Edge c`

辺を取得する

##### Parameters

- `edge_id` : 辺の識別子
- `graph` : グラフ

#### get_size

Type: `CPLib.Graph::Graph c -> Std::I64`

グラフの頂点数を取得する

##### Parameters

- `g` : グラフ

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