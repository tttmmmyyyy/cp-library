# CPLib.Bipartite

Defined in cp-library@0.14.0

二部グラフを扱うモジュール

計算量の n は頂点数（左右の合計）、m は辺数を表します。

## Values

### namespace CPLib.Bipartite::BipartiteGraph

#### add_edge

Type: `Std::I64 -> Std::I64 -> CPLib.Bipartite::BipartiteGraph -> CPLib.Bipartite::BipartiteGraph`

二部グラフに辺を追加する

制約：0 <= left < left_size, 0 <= right < right_size

計算量：ならしO(1)

##### Parameters

- `graph` : 二部グラフ
- `left` : 左側の頂点番号
- `right` : 右側の頂点番号

#### create

Type: `Std::I64 -> Std::I64 -> CPLib.Bipartite::BipartiteGraph`

二部グラフを作成する

計算量：O(1)

##### Parameters

- `left_size` : 左側の頂点数
- `right_size` : 右側の頂点数

#### maximize_flow

Type: `CPLib.Bipartite::BipartiteGraph -> CPLib.Bipartite::BipartiteGraphFlow`

二部グラフに対応する最大フロー問題を作成し、解く

計算量：O((n + m) sqrt(n))

### namespace CPLib.Bipartite::BipartiteGraphFlow

#### get_max_indep_set

Type: `CPLib.Bipartite::BipartiteGraphFlow -> (Std::Array Std::Bool, Std::Array Std::Bool)`

二部グラフの最大孤立集合（最大安定集合）を取得する

計算量：O(n)

##### Returns

左側の頂点の被覆と右側の頂点の被覆をそれぞれ`Array Bool`として返す。
ある頂点が被覆に含まれる場合は`true`、含まれない場合は`false`となる配列が返される。

##### Parameters

- `max_flow` : 二部グラフの最大フロー

#### get_max_matching

Type: `CPLib.Bipartite::BipartiteGraphFlow -> Std::Array Std::Bool`

二部グラフの最大マッチングを取得する

計算量：O(m)

##### Returns

第i番目に追加した辺がマッチングに含まれる場合は`true`、含まれない場合は`false`とする配列

##### Parameters

- `max_flow` : 二部グラフの最大フロー

#### get_min_edge_cover

Type: `CPLib.Bipartite::BipartiteGraphFlow -> Std::Array Std::Bool`

二部グラフの最小辺カバーを取得する

制約：二部グラフに孤立点がない

計算量：O(n + m)

##### Returns

第i番目に追加した辺がカバーに含まれる場合は`true`、含まれない場合は`false`とする配列

##### Parameters

- `max_flow` : 二部グラフの最大フロー

#### get_min_vertex_cover

Type: `CPLib.Bipartite::BipartiteGraphFlow -> (Std::Array Std::Bool, Std::Array Std::Bool)`

二部グラフの最小点被覆を取得する

計算量：O(n)

##### Returns

左側の頂点の被覆と右側の頂点の被覆をそれぞれ`Array Bool`として返す。
ある頂点が被覆に含まれる場合は`true`、含まれない場合は`false`となる配列が返される。

##### Parameters

- `max_flow` : 二部グラフの最大フロー

## Types and aliases

### namespace CPLib.Bipartite

#### BipartiteGraph

Defined as: `type BipartiteGraph = unbox struct { ...fields... }`

二部グラフの型

##### field `left_size`

Type: `Std::I64`

##### field `right_size`

Type: `Std::I64`

##### field `edges`

Type: `Std::Array (Std::I64, Std::I64)`

#### BipartiteGraphFlow

Defined as: `type BipartiteGraphFlow = unbox struct { ...fields... }`

二部グラフに対する最大フロー問題のグラフ

##### field `graph`

Type: `CPLib.Bipartite::BipartiteGraph`

##### field `max_flow`

Type: `CPLib.MaxFlow::MaxFlowGraph Std::I64`

##### field `edge_ids`

Type: `Std::Array CPLib.Graph::EdgeId`

二部グラフの辺に対応する最大フローグラフの辺の識別子

## Traits and aliases

## Trait implementations