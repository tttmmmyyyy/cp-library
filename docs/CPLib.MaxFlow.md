# CPLib.MaxFlow

Defined in cp-library@0.5.1

　最大フロー問題、最小カット問題

## Values

### namespace CPLib.MaxFlow::Dinic

#### bfs

Type: `[c : CPLib.MaxFlow::CapacityLike] CPLib.MaxFlow::MaxFlowGraph c -> CPLib.MaxFlow::MaxFlowGraph c`

残余グラフ上でBFSしてレベルを更新する

#### dfs

Type: `[c : CPLib.MaxFlow::CapacityLike] Std::I64 -> c -> CPLib.MaxFlow::MaxFlowGraph c -> (CPLib.MaxFlow::MaxFlowGraph c, c)`

開始地点からの最短経路DAG（`level`から得られる）においてDFSして経路を一つ発見し、フロー・残余グラフを更新する。

更新された残余グラフと、新たに流されたフローの量を返す。

一度調べた辺を次の`dfs`で調べないよう、`iter`を更新する。

##### Parameters

- `v` : 現在の頂点
- `f` : 流してよいフローの量

#### reset_iter

Type: `CPLib.MaxFlow::MaxFlowGraph c -> CPLib.MaxFlow::MaxFlowGraph c`

`iter`をすべて0にリセットする。

#### reset_level

Type: `CPLib.MaxFlow::MaxFlowGraph c -> CPLib.MaxFlow::MaxFlowGraph c`

`level`をすべて-1にリセットする。

#### solve

Type: `[c : CPLib.MaxFlow::CapacityLike] CPLib.MaxFlow::MaxFlowGraph c -> (CPLib.MaxFlow::MaxFlowGraph c, c)`

最大フローを求める

### namespace CPLib.MaxFlow::MaxFlowGraph

#### add_edge

Type: `[c : CPLib.MaxFlow::CapacityLike] Std::I64 -> Std::I64 -> c -> CPLib.MaxFlow::MaxFlowGraph c -> CPLib.MaxFlow::MaxFlowGraph c`

グラフに辺を追加する

追加された辺の識別子を返す。

##### Parameters

- `graph` : グラフ
- `from` : 始点の頂点番号
- `to` : 終点の頂点番号
- `cap` : 辺の容量

#### add_edge_id

Type: `[c : CPLib.MaxFlow::CapacityLike] Std::I64 -> Std::I64 -> c -> CPLib.MaxFlow::MaxFlowGraph c -> (CPLib.MaxFlow::MaxFlowGraph c, CPLib.Graph::EdgeId)`

グラフに辺を追加する（辺IDを返す）

追加された辺の識別子を返す。

##### Parameters

- `graph` : グラフ
- `from` : 始点の頂点番号
- `to` : 終点の頂点番号
- `cap` : 辺の容量

#### create

Type: `Std::I64 -> Std::I64 -> Std::I64 -> CPLib.MaxFlow::MaxFlowGraph c`

グラフを作成する

##### Parameters

- `n` : 頂点数
- `s` : 開始頂点番号
- `t` : 終了頂点番号

#### get_flow

Type: `[c : CPLib.MaxFlow::CapacityLike] CPLib.Graph::EdgeId -> CPLib.MaxFlow::MaxFlowGraph c -> c`

ある辺に流れているフローを取得する

##### Parameters

- `eid` : `add_edge`で得た辺の識別子
- `graph` : グラフ

#### get_min_cut

Type: `[c : CPLib.MaxFlow::CapacityLike] CPLib.MaxFlow::MaxFlowGraph c -> Std::Array Std::Bool`

最小カットを取得する

先に`maximize_flow`を呼び出しておく必要がある。

`s`から到達可能な頂点を`true`、到達不可能な頂点を`false`とする配列を返す。

注：最小カットにおいて除去される辺の容量の和は`maximize_flow`で得られたフローの量に等しい。

##### Parameters

- `graph` : グラフ

#### maximize_flow

Type: `[c : CPLib.MaxFlow::CapacityLike] CPLib.MaxFlow::MaxFlowGraph c -> (CPLib.MaxFlow::MaxFlowGraph c, c)`

最大フローを計算する

残余グラフと流されたフローの量を返す。

##### Parameters

- `graph` : グラフ

## Types and aliases

### namespace CPLib.MaxFlow

#### MaxFlowGraph

Defined as: `type MaxFlowGraph c = unbox struct { ...fields... }`

最大フロー問題のグラフの型

型パラメータ`c`は容量の型です。

##### field `graph`

Type: `CPLib.Graph::Graph (c, Std::I64, c)`

グラフ。`(現在の容量, 逆辺のインデックス, 初期容量)`

##### field `s`

Type: `Std::I64`

開始地点

##### field `t`

Type: `Std::I64`

終了地点

##### field `level`

Type: `Std::Array Std::I64`

レベル。残余グラフ上での開始地点から任意の地点への距離。到達できない場合は-1。

##### field `iter`

Type: `Std::Array Std::I64`

DFSにおいて次に調べる辺のインデックス

##### field `queue`

Type: `Std::Option (RingBuffer::RingBuffer Std::I64)`

BFSで用いるキュー

## Traits and aliases

## Trait implementations