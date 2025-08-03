# CPLib.Bipartite

Defined in cp-library@0.3.4

二部グラフを扱うモジュール

## Values

### namespace CPLib.Bipartite::BipartiteGraph

#### add_edge

Type: `Std::I64 -> Std::I64 -> CPLib.Bipartite::BipartiteGraph -> CPLib.Bipartite::BipartiteGraph`

二部グラフに辺を追加する

##### Parameters

- `graph` : 二部グラフ
- `left` : 左側の頂点番号
- `right` : 右側の頂点番号

#### create

Type: `Std::I64 -> Std::I64 -> CPLib.Bipartite::BipartiteGraph`

二部グラフを作成する

##### Parameters

- `left_size` : 左側の頂点数
- `right_size` : 右側の頂点数

#### maximize_flow

Type: `CPLib.Bipartite::BipartiteGraph -> CPLib.Bipartite::BipartiteGraphFlow`

二部グラフに対応する最大フロー問題を作成し、解く

### namespace CPLib.Bipartite::BipartiteGraphFlow

#### get_max_matching

Type: `CPLib.Bipartite::BipartiteGraphFlow -> Std::Array Std::Bool`

二部グラフの最大マッチングを取得する

##### Returns

第i番目に追加した辺がマッチングに含まれる場合は`true`、含まれない場合は`false`とする配

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

Type: `Std::Array CPLib.MaxFlow::EdgeId`

二部グラフの辺に対応する最大フローグラフの辺の識別子

## Traits and aliases

## Trait implementations