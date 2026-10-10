# CPLib.MaxFlow

Defined in cp-library@0.15.0

最大フロー問題、最小カット問題

制約・計算量の n は頂点数、m は辺数を表します。

## Examples

```fix
// 頂点0から頂点3への最大フロー
let g = create(4, 0, 3) : MaxFlowGraph I64;
let (g, e01) = g.add_edge_id(0, 1, 2);
let g = g.add_edge(0, 2, 1).add_edge(1, 2, 1).add_edge(1, 3, 1).add_edge(2, 3, 2);
let (g, flow) = g.maximize_flow;
assert_eq(|_|"", flow, 3);;
assert_eq(|_|"", g.get_flow(e01), 2);;
assert_eq(|_|"", g.get_min_cut, [true, false, false, false])
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

Type: `[c : CPLib.MaxFlow::CapacityLike] Std::I64 -> Std::I64 -> c -> CPLib.MaxFlow::MaxFlowGraph c -> (CPLib.MaxFlow::MaxFlowGraph c, Std::I64)`

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

Type: `[c : CPLib.MaxFlow::CapacityLike] Std::I64 -> c -> c -> CPLib.MaxFlow::MaxFlowGraph c -> CPLib.MaxFlow::MaxFlowGraph c`

辺の容量と流れている量を書き換える

他の辺は書き換えないので、流量の保存則が崩れることがある。

制約：0 <= new_flow <= new_cap

計算量：O(1)

##### Parameters

- `edge_id` : `add_edge_id`で得た辺の番号
- `new_cap` : 新しい容量
- `new_flow` : 新しく流れている量
- `graph` : グラフ

#### create

Type: `Std::I64 -> Std::I64 -> Std::I64 -> CPLib.MaxFlow::MaxFlowGraph c`

グラフを作成する

制約：0 <= s, t < n, s != t

計算量：O(1)

##### Parameters

- `n` : 頂点数
- `s` : 開始頂点番号
- `t` : 終了頂点番号

#### get_edge

Type: `[c : CPLib.MaxFlow::CapacityLike] Std::I64 -> CPLib.MaxFlow::MaxFlowGraph c -> CPLib.MaxFlow::MaxFlowEdge c`

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

Type: `[c : CPLib.MaxFlow::CapacityLike] Std::I64 -> CPLib.MaxFlow::MaxFlowGraph c -> c`

辺に流れている量を取得する

計算量：O(1)

##### Parameters

- `edge_id` : `add_edge_id`で得た辺の番号
- `graph` : グラフ

#### get_min_cut

Type: `[c : CPLib.MaxFlow::CapacityLike] CPLib.MaxFlow::MaxFlowGraph c -> Std::Array Std::Bool`

最小カットを取得する

残余グラフの上で、開始地点から到達できる頂点を`true`、到達できない頂点を`false`とする配列を返す。
`maximize_flow`の後では、`true`の頂点の集合が最小カットの開始地点側になる。

計算量：O(n + m)

##### Parameters

- `graph` : グラフ

#### maximize_flow

Type: `[c : CPLib.MaxFlow::CapacityLike] CPLib.MaxFlow::MaxFlowGraph c -> (CPLib.MaxFlow::MaxFlowGraph c, c)`

開始地点から終了地点へ、流せるだけ流す

残余グラフと、新たに流した量を返す。何度でも呼べて、2回目以降は前回の残余グラフから流す。

制約：最大流量 < `Inf::inf`

計算量：O(n^2 m)。辺の容量がすべて1ならO((n + m) sqrt(m))

##### Parameters

- `graph` : グラフ

#### maximize_flow_with_limit

Type: `[c : CPLib.MaxFlow::CapacityLike] c -> CPLib.MaxFlow::MaxFlowGraph c -> (CPLib.MaxFlow::MaxFlowGraph c, c)`

開始地点から終了地点へ、流した量が上限に達するまで、流せるだけ流す

残余グラフと、新たに流した量（上限以下）を返す。何度でも呼べて、2回目以降は前回の残余グラフから流す。

計算量：O(n^2 m)。辺の容量がすべて1ならO((n + m) sqrt(m))

##### Parameters

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

#### MaxFlowGraph

Defined as: `type MaxFlowGraph c = unbox struct { ...fields... }`

最大フロー問題のグラフの型

型パラメータ`c`は容量の型です。

辺には足した順に0から番号を振る。内部では、k番目に足した辺を番号2kで、その逆辺を番号2k + 1で表す。

##### field `n`

Type: `Std::I64`

頂点数

##### field `s`

Type: `Std::I64`

開始地点

##### field `t`

Type: `Std::I64`

終了地点

##### field `to`

Type: `Std::Array Std::I64`

内部の辺ごとの行き先の頂点（長さは足した辺の数の2倍）

##### field `cap`

Type: `Std::Array c`

内部の辺ごとの残余容量（長さは足した辺の数の2倍）。k番目に足した辺の逆辺の残余容量は、その辺に流れている量に等しい

#### ResidualGraph

Defined as: `type ResidualGraph c = unbox struct { ...fields... }`

最大フローを求める間の残余グラフ

内部の辺を始点ごとにまとめて並べる（CSR形式）。頂点vから出る辺は、位置[start.@(v), start.@(v + 1))にある。
同じ頂点から出る辺のデータが続けて並ぶので、頂点の辺をたどる読み出しが近い場所に集まる。

##### field `start`

Type: `Std::Array Std::I64`

長さが頂点数 + 1の配列。頂点vから出る辺の位置は[start.@(v), start.@(v + 1))

##### field `pos`

Type: `Std::Array Std::I64`

内部の辺の番号ごとの位置

##### field `to`

Type: `Std::Array Std::I64`

位置ごとの行き先の頂点

##### field `rev`

Type: `Std::Array Std::I64`

位置ごとの、逆辺の位置

##### field `cap`

Type: `Std::Array c`

位置ごとの残余容量

## Traits and aliases

### namespace CPLib.MaxFlow

#### trait `CapacityLike = Std::Additive + Std::Neg + Std::LessThan + Std::Eq + CPLib.Trait::Inf`

Kind: `*`

容量に要求されるトレイト

## Trait implementations