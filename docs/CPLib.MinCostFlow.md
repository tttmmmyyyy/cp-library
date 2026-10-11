# CPLib.MinCostFlow

Defined in cp-library@0.15.0

最小費用流問題

制約・計算量の n は頂点数、m は辺数を表します。

## Examples

```fix
// 容量とコストを指定した辺を張る
let g = create(3) : MinCostFlowGraph I64;
let g = g.add_edge(0, 1, 2, 1).add_edge(1, 2, 1, 1).add_edge(0, 2, 1, 5);
// 頂点0から頂点2へ流量の上限を10として流すと、流量2（0->1->2と0->2に1ずつ）、コスト2 + 5 = 7
let (_, flow, cost) = g.maximize_flow_min_cost_with_limit(0, 2, 10);
assert_eq(|_|"", (flow, cost), (2, 7))
```

## Values

### namespace CPLib.MinCostFlow::MinCostFlowGraph

#### add_edge

Type: `[c : CPLib.MinCostFlow::CapCostLike] Std::I64 -> Std::I64 -> c -> c -> CPLib.MinCostFlow::MinCostFlowGraph c -> CPLib.MinCostFlow::MinCostFlowGraph c`

グラフに辺を追加する

制約：0 <= from, to < n, cap >= 0

計算量：ならしO(1)

##### Parameters

- `from` : 始点の頂点番号
- `to` : 終点の頂点番号
- `cap` : 辺の容量
- `cost` : 辺の流量1あたりのコスト
- `graph` : グラフ

#### add_edge_id

Type: `[c : CPLib.MinCostFlow::CapCostLike] Std::I64 -> Std::I64 -> c -> c -> CPLib.MinCostFlow::MinCostFlowGraph c -> (CPLib.MinCostFlow::MinCostFlowGraph c, CPLib.MinCostFlow::MinCostFlowEdgeId)`

グラフに辺を追加する（辺の番号を返す）

辺の番号は、`add_edge`で足した辺も含めて、足した順に0から振られる。

制約：0 <= from, to < n, cap >= 0

計算量：ならしO(1)

##### Parameters

- `from` : 始点の頂点番号
- `to` : 終点の頂点番号
- `cap` : 辺の容量
- `cost` : 辺の流量1あたりのコスト
- `graph` : グラフ

#### create

Type: `Std::I64 -> CPLib.MinCostFlow::MinCostFlowGraph c`

辺のないグラフを作成する

計算量：O(1)

##### Parameters

- `n` : 頂点数

#### get_edge

Type: `[c : CPLib.MinCostFlow::CapCostLike] CPLib.MinCostFlow::MinCostFlowEdgeId -> CPLib.MinCostFlow::MinCostFlowGraph c -> CPLib.MinCostFlow::MinCostFlowEdge c`

辺の状態を取得する

計算量：O(1)

##### Parameters

- `edge_id` : 辺の番号（0 <= edge_id < 足した辺の数）
- `graph` : グラフ

#### get_edges

Type: `[c : CPLib.MinCostFlow::CapCostLike] CPLib.MinCostFlow::MinCostFlowGraph c -> Std::Array (CPLib.MinCostFlow::MinCostFlowEdge c)`

すべての辺の状態を、足した順に並べて取得する

計算量：O(m)

##### Parameters

- `graph` : グラフ

#### get_flow

Type: `[c : CPLib.MinCostFlow::CapCostLike] CPLib.MinCostFlow::MinCostFlowEdgeId -> CPLib.MinCostFlow::MinCostFlowGraph c -> c`

辺に流れている量を取得する

計算量：O(1)

##### Parameters

- `edge_id` : 辺の番号（0 <= edge_id < 足した辺の数）
- `graph` : グラフ

#### maximize_flow_min_cost

Type: `[c : CPLib.MinCostFlow::CapCostLike] Std::I64 -> Std::I64 -> CPLib.MinCostFlow::MinCostFlowGraph c -> (CPLib.MinCostFlow::MinCostFlowGraph c, c, c)`

頂点`s`から頂点`t`へ流せるだけ流し、その流量を流すコストを最小にする

流した後のグラフと、新たに流した量と、そのコストを返す。
何度でも呼べて、2回目以降はそれまでに流した状態から続けて流す。`s`と`t`は呼ぶたびに変えてよい。

制約：
- 0 <= s, t < n, s != t
- 残余グラフに、コストの和が負の閉路がない。負のコストの辺があってもよい。破ると理由を書いて止まる
- 流量とコストの総和が`c`に収まる
- n * (辺のコストの絶対値の最大) <= 8e18（`c`が`I64`のとき）

計算量：O(F (n + m) log(n + m))、Fは流した量（容量が整数のとき）。
残余グラフに負のコストの辺があるとき（負のコストの辺を足したときと、2回目以降に呼ぶとき）は、O(n m)を足す

##### Parameters

- `s` : 流し出す頂点の番号
- `t` : 流し込む頂点の番号
- `graph` : グラフ

#### maximize_flow_min_cost_with_limit

Type: `[c : CPLib.MinCostFlow::CapCostLike] Std::I64 -> Std::I64 -> c -> CPLib.MinCostFlow::MinCostFlowGraph c -> (CPLib.MinCostFlow::MinCostFlowGraph c, c, c)`

頂点`s`から頂点`t`へ、流した量が上限に達するまで流せるだけ流し、その流量を流すコストを最小にする

流した後のグラフと、新たに流した量（上限以下）と、そのコストを返す。上限が0以下なら何も流さず0を返す。
何度でも呼べて、2回目以降はそれまでに流した状態から続けて流す。`s`と`t`は呼ぶたびに変えてよい。

制約：
- 0 <= s, t < n, s != t
- 残余グラフに、コストの和が負の閉路がない。負のコストの辺があってもよい。破ると理由を書いて止まる
- 流量とコストの総和が`c`に収まる
- n * (辺のコストの絶対値の最大) <= 8e18（`c`が`I64`のとき）

計算量：O(F (n + m) log(n + m))、Fは流した量（容量が整数のとき）。
残余グラフに負のコストの辺があるとき（負のコストの辺を足したときと、2回目以降に呼ぶとき）は、O(n m)を足す

##### Parameters

- `s` : 流し出す頂点の番号
- `t` : 流し込む頂点の番号
- `flow_limit` : 流す量の上限
- `graph` : グラフ

## Types and aliases

### namespace CPLib.MinCostFlow

#### MinCostFlowEdge

Defined as: `type MinCostFlowEdge c = unbox struct { ...fields... }`

最小費用流問題のグラフの辺の状態

##### field `from`

Type: `Std::I64`

始点の頂点番号

##### field `to`

Type: `Std::I64`

終点の頂点番号

##### field `cap`

Type: `c`

容量

##### field `flow`

Type: `c`

流れている量

##### field `cost`

Type: `c`

流量1あたりのコスト

#### MinCostFlowEdgeId

Defined as: `type MinCostFlowEdgeId = Std::I64`

最小費用流問題のグラフの辺の番号

`add_edge`と`add_edge_id`で足した辺に、足した順に0から振られる。足した辺がm本なら、番号は0以上m未満である。

#### MinCostFlowGraph

Defined as: `type MinCostFlowGraph c = unbox struct { ...fields... }`

最小費用流問題のグラフの型

型パラメータ`c`は容量とコストの型です。

## Traits and aliases

### namespace CPLib.MinCostFlow

#### trait `CapCostLike = Std::Additive + Std::Mul + Std::Neg + Std::Sub + Std::LessThan + CPLib.Trait::Inf + Std::Eq`

Kind: `*`

フローの容量およびコストに要求されるトレイト

注：Fixの`Mul`トレイトは`lhs`と`rhs`に同じ型のみを受け付けるため、容量とコストは同じ型である必要があります。

## Trait implementations