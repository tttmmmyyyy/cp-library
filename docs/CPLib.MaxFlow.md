# CPLib.MaxFlow

Defined in cp-library@0.15.0

最大フロー問題、最小カット問題

制約・計算量の n は頂点数、m は辺数を表します。

## Examples

```fix
// 頂点0から頂点3への最大フロー
let g = create(4) : MaxFlowGraph I64;
let (g, e01) = g.add_edge_id(0, 1, 2);
let g = g.add_edge(0, 2, 1).add_edge(1, 2, 1).add_edge(1, 3, 1).add_edge(2, 3, 2);
let (g, flow) = g.maximize_flow(0, 3);
assert_eq(|_|"", flow, 3);;
assert_eq(|_|"", g.get_flow(e01), 2);;
assert_eq(|_|"", g.get_min_cut(0), [true, false, false, false])
```

## Values

### namespace CPLib.MaxFlow::MaxFlowGraph

#### add_edge

Type: `[c : CPLib.MaxFlow::CapacityLike] Std::I64 -> Std::I64 -> c -> CPLib.MaxFlow::MaxFlowGraph c -> CPLib.MaxFlow::MaxFlowGraph c`

グラフに辺を追加する

制約：0 <= from, to < n, cap >= 0

計算量：ならしO(1)

##### Parameters

- `from` : 始点の頂点番号
- `to` : 終点の頂点番号
- `cap` : 辺の容量
- `graph` : グラフ

#### add_edge_id

Type: `[c : CPLib.MaxFlow::CapacityLike] Std::I64 -> Std::I64 -> c -> CPLib.MaxFlow::MaxFlowGraph c -> (CPLib.MaxFlow::MaxFlowGraph c, CPLib.MaxFlow::MaxFlowEdgeId)`

グラフに辺を追加する（辺の番号を返す）

辺の番号は、足した順に0から振られる。

制約：0 <= from, to < n, cap >= 0

計算量：ならしO(1)

##### Parameters

- `from` : 始点の頂点番号
- `to` : 終点の頂点番号
- `cap` : 辺の容量
- `graph` : グラフ

#### change_edge

Type: `[c : CPLib.MaxFlow::CapacityLike] CPLib.MaxFlow::MaxFlowEdgeId -> c -> c -> CPLib.MaxFlow::MaxFlowGraph c -> CPLib.MaxFlow::MaxFlowGraph c`

辺の容量と流れている量を書き換える

他の辺は書き換えないので、辺の両端の頂点で、流れ込む量と流れ出す量が等しくなくなることがある。

制約：0 <= new_flow <= new_cap

計算量：O(1)

##### Parameters

- `edge_id` : `add_edge_id`で得た辺の番号
- `new_cap` : 新しい容量
- `new_flow` : 新しく流れている量
- `graph` : グラフ

#### create

Type: `Std::I64 -> CPLib.MaxFlow::MaxFlowGraph c`

辺のないグラフを作成する

計算量：O(1)

##### Parameters

- `n` : 頂点数

#### get_edge

Type: `[c : CPLib.MaxFlow::CapacityLike] CPLib.MaxFlow::MaxFlowEdgeId -> CPLib.MaxFlow::MaxFlowGraph c -> CPLib.MaxFlow::MaxFlowEdge c`

辺の状態を取得する

計算量：O(1)

##### Parameters

- `edge_id` : `add_edge_id`で得た辺の番号
- `graph` : グラフ

#### get_edges

Type: `[c : CPLib.MaxFlow::CapacityLike] CPLib.MaxFlow::MaxFlowGraph c -> Std::Array (CPLib.MaxFlow::MaxFlowEdge c)`

すべての辺の状態を、足した順に並べて取得する

計算量：O(m)

##### Parameters

- `graph` : グラフ

#### get_flow

Type: `[c : CPLib.MaxFlow::CapacityLike] CPLib.MaxFlow::MaxFlowEdgeId -> CPLib.MaxFlow::MaxFlowGraph c -> c`

辺に流れている量を取得する

計算量：O(1)

##### Parameters

- `edge_id` : `add_edge_id`で得た辺の番号
- `graph` : グラフ

#### get_min_cut

Type: `[c : CPLib.MaxFlow::CapacityLike] Std::I64 -> CPLib.MaxFlow::MaxFlowGraph c -> Std::Array Std::Bool`

最小カットを取得する

残余グラフの上で、頂点`s`から到達できる頂点を`true`、到達できない頂点を`false`とする配列を返す。
`maximize_flow(s, t)`の後では、`true`の頂点の集合が、`s`と`t`を分ける最小カットの`s`の側になる。

制約：0 <= s < n

計算量：O(n + m)

##### Parameters

- `s` : 到達を調べる始点の頂点番号
- `graph` : グラフ

#### maximize_flow

Type: `[c : CPLib.MaxFlow::CapacityLike] Std::I64 -> Std::I64 -> CPLib.MaxFlow::MaxFlowGraph c -> (CPLib.MaxFlow::MaxFlowGraph c, c)`

頂点`s`から頂点`t`へ、流せるだけ流す

流した後のグラフと、新たに流した量を返す。何度でも呼べて、2回目以降はそれまでに流した状態から続けて流す。
`s`と`t`以外の各頂点では、流れ込む量と流れ出す量の差を変えずに流す。

制約：0 <= s, t < n, s != t、流せる量 < `Inf::inf`

計算量：O(n^2 m)。辺の容量がすべて1ならO((n + m) sqrt(m))

##### Parameters

- `s` : 流し出す頂点の番号
- `t` : 流し込む頂点の番号
- `graph` : グラフ

#### maximize_flow_with_limit

Type: `[c : CPLib.MaxFlow::CapacityLike] Std::I64 -> Std::I64 -> c -> CPLib.MaxFlow::MaxFlowGraph c -> (CPLib.MaxFlow::MaxFlowGraph c, c)`

頂点`s`から頂点`t`へ、流した量が上限に達するまで、流せるだけ流す

流した後のグラフと、新たに流した量（上限以下）を返す。何度でも呼べて、2回目以降はそれまでに流した状態から続けて流す。
`s`と`t`以外の各頂点では、流れ込む量と流れ出す量の差を変えずに流す。

制約：0 <= s, t < n, s != t

計算量：O(n^2 m)。辺の容量がすべて1ならO((n + m) sqrt(m))

##### Parameters

- `s` : 流し出す頂点の番号
- `t` : 流し込む頂点の番号
- `flow_limit` : 流す量の上限
- `graph` : グラフ

## Types and aliases

### namespace CPLib.MaxFlow

#### MaxFlowEdge

Defined as: `type MaxFlowEdge c = unbox struct { ...fields... }`

最大フロー問題のグラフの辺の状態

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

#### MaxFlowEdgeId

Defined as: `type MaxFlowEdgeId = Std::I64`

最大フロー問題のグラフの辺の番号

`add_edge_id`が返す。辺には足した順に0から番号が振られる。

#### MaxFlowGraph

Defined as: `type MaxFlowGraph c = unbox struct { ...fields... }`

最大フロー問題のグラフの型

型パラメータ`c`は容量の型です。

## Traits and aliases

### namespace CPLib.MaxFlow

#### trait `CapacityLike = Std::Additive + Std::Neg + Std::LessThan + Std::Eq + CPLib.Trait::Inf`

Kind: `*`

容量に要求されるトレイト

## Trait implementations