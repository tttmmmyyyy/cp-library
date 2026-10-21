# CPLib.MinCostFlow

Defined in cp-library@0.15.2

最小費用流問題

制約・計算量の n は頂点数、m は辺数を表します。

## Examples

```fix
// 容量とコストを指定した辺を張る
let g = create(3);
let g = g.add_edge(0, 1, 2, 1).add_edge(1, 2, 1, 1);
let (g, e02) = g.add_edge_id(0, 2, 1, 5);
// 頂点0から頂点2へ流すと、流量2（0->1->2と0->2に1ずつ）、コスト2 + 5 = 7
let (g, flow, cost) = g.maximize_flow_min_cost(0, 2);
assert_eq(|_|"", (flow, cost), (2, 7));;
assert_eq(|_|"", g.get_flow(e02), 1)
```

## Values

### namespace CPLib.MinCostFlow::MinCostFlowGraph

#### add_edge

Type: `Std::I64 -> Std::I64 -> Std::I64 -> Std::I64 -> CPLib.MinCostFlow::MinCostFlowGraph -> CPLib.MinCostFlow::MinCostFlowGraph`

グラフに辺を追加する

制約：0 <= from, to < n, cap >= 0。costは負でもよい（負の閉路については、型`MinCostFlowGraph`の説明にある、`maximize_flow_min_cost`、`maximize_flow_min_cost_with_limit`、`maximize_flow_min_cost_slope`、`maximize_flow_min_cost_slope_with_limit`の制約を見よ）

計算量：ならしO(1)

##### Parameters

- `from` : 始点の頂点番号
- `to` : 終点の頂点番号
- `cap` : 辺の容量
- `cost` : 辺の流量1あたりのコスト
- `graph` : グラフ

#### add_edge_id

Type: `Std::I64 -> Std::I64 -> Std::I64 -> Std::I64 -> CPLib.MinCostFlow::MinCostFlowGraph -> (CPLib.MinCostFlow::MinCostFlowGraph, CPLib.MinCostFlow::MinCostFlowEdgeId)`

グラフに辺を追加する（辺の番号を返す）

辺の番号は、`add_edge`で足した辺も含めて、足した順に0から振られる。

制約：0 <= from, to < n, cap >= 0。costは負でもよい（負の閉路については、型`MinCostFlowGraph`の説明にある、`maximize_flow_min_cost`、`maximize_flow_min_cost_with_limit`、`maximize_flow_min_cost_slope`、`maximize_flow_min_cost_slope_with_limit`の制約を見よ）

計算量：ならしO(1)

##### Parameters

- `from` : 始点の頂点番号
- `to` : 終点の頂点番号
- `cap` : 辺の容量
- `cost` : 辺の流量1あたりのコスト
- `graph` : グラフ

#### create

Type: `Std::I64 -> CPLib.MinCostFlow::MinCostFlowGraph`

辺のないグラフを作成する

計算量：O(1)

##### Parameters

- `n` : 頂点数

#### get_edge

Type: `CPLib.MinCostFlow::MinCostFlowEdgeId -> CPLib.MinCostFlow::MinCostFlowGraph -> CPLib.MinCostFlow::MinCostFlowEdge`

辺の状態を取得する

計算量：O(1)

##### Parameters

- `edge_id` : 辺の番号（0 <= edge_id < 足した辺の数）
- `graph` : グラフ

#### get_edges

Type: `CPLib.MinCostFlow::MinCostFlowGraph -> Std::Array CPLib.MinCostFlow::MinCostFlowEdge`

すべての辺の状態を、足した順に並べて取得する

計算量：O(m)

##### Parameters

- `graph` : グラフ

#### get_flow

Type: `CPLib.MinCostFlow::MinCostFlowEdgeId -> CPLib.MinCostFlow::MinCostFlowGraph -> Std::I64`

辺に流れている量を取得する

計算量：O(1)

##### Parameters

- `edge_id` : 辺の番号（0 <= edge_id < 足した辺の数）
- `graph` : グラフ

#### maximize_flow_min_cost

Type: `Std::I64 -> Std::I64 -> CPLib.MinCostFlow::MinCostFlowGraph -> (CPLib.MinCostFlow::MinCostFlowGraph, Std::I64, Std::I64)`

頂点`s`から頂点`t`へ流せるだけ流し、その流量を流すコストを最小にする

流した後のグラフと、新たに流した量と、そのコストを返す。
何度でも呼べて、2回目以降はそれまでに流した状態から続けて流す。`s`と`t`は呼ぶたびに変えてよい。

制約：型`MinCostFlowGraph`の説明にある、この関数の制約を見よ

計算量：O(F (n + m) log(n + m))、Fは流した量。
容量が正の辺にコストが負のものがあるとき（負のコストの辺を足したときと、2回目以降に呼ぶとき）は、追加でO(n (n + m))かかる。
流す量によらず、呼ぶたびにO(n + m)かかる

##### Parameters

- `s` : 流し出す頂点の番号
- `t` : 流し込む頂点の番号
- `graph` : グラフ

#### maximize_flow_min_cost_slope

Type: `Std::I64 -> Std::I64 -> CPLib.MinCostFlow::MinCostFlowGraph -> (CPLib.MinCostFlow::MinCostFlowGraph, Std::Array (Std::I64, Std::I64))`

頂点`s`から頂点`t`へ流せるだけ流し、流量ごとの最小コストを折れ線で返す

流量xを流すときの最小コストをg(x)とすると、gは下に凸な折れ線である。流した後のグラフと、gの折れ点(x, g(x))の列を返す。
xはこの呼び出しで流した量、g(x)はそのコストである。
- 最初の点は(0, 0)、最後の点は(流した量, そのコスト)
- xは狭義単調増加で、3点が一直線に並ぶことはない

何度でも呼べて、2回目以降はそれまでに流した状態から続けて流す。`s`と`t`は呼ぶたびに変えてよい。

制約：型`MinCostFlowGraph`の説明にある、この関数の制約を見よ

計算量：O(F (n + m) log(n + m))、Fは流した量。
容量が正の辺にコストが負のものがあるとき（負のコストの辺を足したときと、2回目以降に呼ぶとき）は、追加でO(n (n + m))かかる。
流す量によらず、呼ぶたびにO(n + m)かかる

##### Parameters

- `s` : 流し出す頂点の番号
- `t` : 流し込む頂点の番号
- `graph` : グラフ

#### maximize_flow_min_cost_slope_with_limit

Type: `Std::I64 -> Std::I64 -> Std::I64 -> CPLib.MinCostFlow::MinCostFlowGraph -> (CPLib.MinCostFlow::MinCostFlowGraph, Std::Array (Std::I64, Std::I64))`

頂点`s`から頂点`t`へ、流した量が上限に達するまで流せるだけ流し、流量ごとの最小コストを折れ線で返す

`maximize_flow_min_cost_slope`と同じく、流した後のグラフと、流量ごとの最小コストの折れ点の列を返す。
最後の点の流量は上限以下である。上限が0以下なら何も流さず[(0, 0)]を返す。

制約：型`MinCostFlowGraph`の説明にある、この関数の制約を見よ

計算量：O(F (n + m) log(n + m))、Fは流した量。
容量が正の辺にコストが負のものがあるとき（負のコストの辺を足したときと、2回目以降に呼ぶとき）は、追加でO(n (n + m))かかる。
流す量によらず、呼ぶたびにO(n + m)かかる

##### Parameters

- `s` : 流し出す頂点の番号
- `t` : 流し込む頂点の番号
- `flow_limit` : 流す量の上限
- `graph` : グラフ

#### maximize_flow_min_cost_with_limit

Type: `Std::I64 -> Std::I64 -> Std::I64 -> CPLib.MinCostFlow::MinCostFlowGraph -> (CPLib.MinCostFlow::MinCostFlowGraph, Std::I64, Std::I64)`

頂点`s`から頂点`t`へ、流した量が上限に達するまで流せるだけ流し、その流量を流すコストを最小にする

流した後のグラフと、新たに流した量（上限以下）と、そのコストを返す。上限が0以下なら何も流さず0を返す。
何度でも呼べて、2回目以降はそれまでに流した状態から続けて流す。`s`と`t`は呼ぶたびに変えてよい。

制約：型`MinCostFlowGraph`の説明にある、この関数の制約を見よ

計算量：O(F (n + m) log(n + m))、Fは流した量。
容量が正の辺にコストが負のものがあるとき（負のコストの辺を足したときと、2回目以降に呼ぶとき）は、追加でO(n (n + m))かかる。
流す量によらず、呼ぶたびにO(n + m)かかる

##### Parameters

- `s` : 流し出す頂点の番号
- `t` : 流し込む頂点の番号
- `flow_limit` : 流す量の上限
- `graph` : グラフ

## Types and aliases

### namespace CPLib.MinCostFlow

#### MinCostFlowEdge

Defined as: `type MinCostFlowEdge = unbox struct { ...fields... }`

最小費用流問題のグラフの辺の状態

##### field `from`

Type: `Std::I64`

始点の頂点番号

##### field `to`

Type: `Std::I64`

終点の頂点番号

##### field `cap`

Type: `Std::I64`

容量

##### field `flow`

Type: `Std::I64`

流れている量

##### field `cost`

Type: `Std::I64`

流量1あたりのコスト

#### MinCostFlowEdgeId

Defined as: `type MinCostFlowEdgeId = Std::I64`

最小費用流問題のグラフの辺の番号

`add_edge`と`add_edge_id`で足した辺に、足した順に0から振られる。足した辺がm本なら、番号は0以上m未満である。

#### MinCostFlowGraph

Defined as: `type MinCostFlowGraph = unbox struct { ...fields... }`

最小費用流問題のグラフの型

容量とコストは`I64`で表す。

`maximize_flow_min_cost`、`maximize_flow_min_cost_with_limit`、`maximize_flow_min_cost_slope`、`maximize_flow_min_cost_slope_with_limit`の制約：
- 0 <= s, t < n, s != t
- 負の閉路がない：容量が正の辺をたどる閉路で、コストの和が負のものがない。
  流した後に辺を足してから再度流すときは、流れている辺の逆向き（コストの符号を反転した辺）も閉路に含める。
  `s`から届く負の閉路があると、理由を標準エラー出力に出力してプログラムを終了する
- 辺のコストの絶対値の最大をCとして、n * C <= 5e17
- 容量の総和と、容量 * |コスト| の総和が、どちらも4e18以下

## Traits and aliases

## Trait implementations