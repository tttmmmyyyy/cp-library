# CPLib.MinCostFlow

Defined in cp-library@0.14.0

最小コスト最大流問題

制約・計算量の n は頂点数、m は辺数を表します。

## Values

### namespace CPLib.MinCostFlow::MinCostFlowGraph

#### add_edge

Type: `[c : CPLib.MinCostFlow::CapCostLike] Std::I64 -> Std::I64 -> c -> c -> CPLib.MinCostFlow::MinCostFlowGraph c -> CPLib.MinCostFlow::MinCostFlowGraph c`

グラフに辺を追加する

制約：0 <= from, to < n, cap >= 0

計算量：ならしO(1)

##### Parameters

- `graph` : グラフ
- `from` : 始点の頂点番号
- `to` : 終点の頂点番号
- `cap` : 辺の容量
- `cost` : 辺のコスト

#### add_edge_id

Type: `[c : CPLib.MinCostFlow::CapCostLike] Std::I64 -> Std::I64 -> c -> c -> CPLib.MinCostFlow::MinCostFlowGraph c -> (CPLib.MinCostFlow::MinCostFlowGraph c, CPLib.Graph::EdgeId)`

グラフに辺を追加する（辺IDを返す）

追加された辺の識別子を返す。

制約：0 <= from, to < n, cap >= 0

計算量：ならしO(1)

##### Parameters

- `graph` : グラフ
- `from` : 始点の頂点番号
- `to` : 終点の頂点番号
- `cap` : 辺の容量
- `cost` : 辺のコスト

#### create

Type: `[c : CPLib.MinCostFlow::CapCostLike] Std::I64 -> Std::I64 -> Std::I64 -> CPLib.MinCostFlow::MinCostFlowGraph c`

グラフを作成する

制約：0 <= s, t < n, s != t

計算量：O(n)

##### Parameters

- `n` : 頂点数
- `s` : 開始頂点番号
- `t` : 終了頂点番号

#### get_flow

Type: `[c : CPLib.MinCostFlow::CapCostLike] CPLib.Graph::EdgeId -> CPLib.MinCostFlow::MinCostFlowGraph c -> c`

ある辺に流れているフローを取得する

計算量：O(1)

##### Parameters

- `eid` : `add_edge`で得た辺の識別子
- `graph` : グラフ

#### maximize_flow_min_cost

Type: `[c : CPLib.MinCostFlow::CapCostLike] c -> CPLib.MinCostFlow::MinCostFlowGraph c -> (CPLib.MinCostFlow::MinCostFlowGraph c, c, c)`

最小コスト最大フローを計算する

指定された量を上限として流せるだけ流し、流れたフローとコストを返す。

制約：
- 辺のコスト >= 0（負のコストの辺があるときは、先に`set_potential_bf`を呼ぶ）
- 流量とコストの総和が`c`に収まる
- n * (辺のコストの絶対値の最大) <= 8e18（`c`が`I64`のとき）

計算量：O(F (n + m) log(n + m))、Fは流量（容量が整数のとき）

##### Parameters

- `flow_limit` : 流すフローの最大値
- `g` : 最小フロー問題のグラフ

#### set_potential_bf

Type: `[c : CPLib.MinCostFlow::CapCostLike] CPLib.MinCostFlow::MinCostFlowGraph c -> CPLib.MinCostFlow::MinCostFlowGraph c`

ベルマンフォード法を使ってポテンシャルを更新する

ベルマンフォード法を使って`graph.@potential`を更新し、負の辺がある場合も動作するようにします。

制約：負の閉路がない

計算量：O(n (n + m))

## Types and aliases

### namespace CPLib.MinCostFlow

#### EdgeData

Defined as: `type EdgeData c = unbox struct { ...fields... }`

##### field `cost`

Type: `c`

コスト

##### field `cap`

Type: `c`

現在の容量

##### field `rev`

Type: `Std::I64`

逆辺のインデックス

##### field `init_cap`

Type: `c`

初期容量

#### MinCostFlowGraph

Defined as: `type MinCostFlowGraph c = unbox struct { ...fields... }`

最小フロー問題のグラフの型

##### field `graph`

Type: `CPLib.Graph::Graph (CPLib.MinCostFlow::EdgeData c)`

グラフ

##### field `s`

Type: `Std::I64`

開始地点

##### field `t`

Type: `Std::I64`

終了地点

##### field `potential`

Type: `Std::Array c`

ポテンシャル

## Traits and aliases

### namespace CPLib.MinCostFlow

#### trait `CapCostLike = Std::Additive + Std::Mul + Std::Neg + Std::Sub + Std::LessThan + CPLib.Trait::Inf + Std::Eq`

Kind: `*`

フローの容量およびコストに要求されるトレイト

注：Fixの`Mul`トレイトは`lhs`と`rhs`に同じ型のみを受け付けるため、容量とコストは同じ型である必要があります。

## Trait implementations