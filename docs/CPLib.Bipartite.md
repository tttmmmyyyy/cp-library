# CPLib.Bipartite

Defined in cp-library@0.15.1

二部グラフを扱うモジュール

計算量の n は頂点数（左右の合計）、m は辺数を表します。

## Examples

```fix
// 左右に2頂点ずつある二部グラフ
let g = create(2, 2).add_edge(0, 0).add_edge(0, 1).add_edge(1, 1);
let flow = g.calc_flow;
// 最大マッチングは辺(0, 0)と辺(1, 1)
assert_eq(|_|"", flow.get_max_matching, [true, false, true])
```

## Values

### namespace CPLib.Bipartite::BipartiteGraph

#### @edges

Type: `CPLib.Bipartite::BipartiteGraph -> Std::Array (Std::I64, Std::I64)`

辺の配列を取得する

第`i`要素は、`i`番目に追加した辺の（左側の頂点番号, 右側の頂点番号）です。

計算量：O(1)

##### Parameters

- `graph` : 二部グラフ

#### @left_size

Type: `CPLib.Bipartite::BipartiteGraph -> Std::I64`

左側の頂点数を取得する

計算量：O(1)

##### Parameters

- `graph` : 二部グラフ

#### @right_size

Type: `CPLib.Bipartite::BipartiteGraph -> Std::I64`

右側の頂点数を取得する

計算量：O(1)

##### Parameters

- `graph` : 二部グラフ

#### add_edge

Type: `Std::I64 -> Std::I64 -> CPLib.Bipartite::BipartiteGraph -> CPLib.Bipartite::BipartiteGraph`

二部グラフに辺を追加する

制約：0 <= left < left_size, 0 <= right < right_size

計算量：ならしO(1)

##### Parameters

- `left` : 左側の頂点番号
- `right` : 右側の頂点番号
- `graph` : 二部グラフ

#### calc_flow

Type: `CPLib.Bipartite::BipartiteGraph -> CPLib.Bipartite::BipartiteGraphFlow`

二部グラフに対応する最大フロー問題を作成し、解く

計算量：O((n + m) sqrt(n))

#### create

Type: `Std::I64 -> Std::I64 -> CPLib.Bipartite::BipartiteGraph`

二部グラフを作成する

計算量：O(1)

##### Parameters

- `left_size` : 左側の頂点数
- `right_size` : 右側の頂点数

#### maximize_flow

**Deprecated**: Use `CPLib.Bipartite::BipartiteGraph::calc_flow` instead.

Type: `CPLib.Bipartite::BipartiteGraph -> CPLib.Bipartite::BipartiteGraphFlow`

`calc_flow`の別名（非推奨）

### namespace CPLib.Bipartite::BipartiteGraphFlow

#### calc_max_indep_set

Type: `CPLib.Bipartite::BipartiteGraphFlow -> (Std::Array Std::Bool, Std::Array Std::Bool)`

二部グラフの最大独立集合（最大安定集合）を取得する

計算量：O(n + m)

##### Returns

左側の頂点と右側の頂点のそれぞれについて、最大独立集合に含まれる頂点を`true`、含まれない頂点を`false`とする`Array Bool`を返す。

##### Parameters

- `max_flow` : 二部グラフの最大フロー

#### calc_min_edge_cover

Type: `CPLib.Bipartite::BipartiteGraphFlow -> Std::Array Std::Bool`

二部グラフの最小辺カバーを取得する

制約：二部グラフに孤立点がない

計算量：O(n + m)

##### Returns

第i番目に追加した辺がカバーに含まれる場合は`true`、含まれない場合は`false`とする配列

##### Parameters

- `max_flow` : 二部グラフの最大フロー

#### calc_min_vertex_cover

Type: `CPLib.Bipartite::BipartiteGraphFlow -> (Std::Array Std::Bool, Std::Array Std::Bool)`

二部グラフの最小点被覆を取得する

計算量：O(n + m)

##### Returns

左側の頂点の被覆と右側の頂点の被覆をそれぞれ`Array Bool`として返す。
ある頂点が被覆に含まれる場合は`true`、含まれない場合は`false`となる配列が返される。

##### Parameters

- `max_flow` : 二部グラフの最大フロー

#### get_max_indep_set

**Deprecated**: Use `CPLib.Bipartite::BipartiteGraphFlow::calc_max_indep_set` instead.

Type: `CPLib.Bipartite::BipartiteGraphFlow -> (Std::Array Std::Bool, Std::Array Std::Bool)`

`calc_max_indep_set`の別名（非推奨）

#### get_max_matching

Type: `CPLib.Bipartite::BipartiteGraphFlow -> Std::Array Std::Bool`

二部グラフの最大マッチングを取得する

計算量：O(m)

##### Returns

第i番目に追加した辺がマッチングに含まれる場合は`true`、含まれない場合は`false`とする配列

##### Parameters

- `max_flow` : 二部グラフの最大フロー

#### get_min_edge_cover

**Deprecated**: Use `CPLib.Bipartite::BipartiteGraphFlow::calc_min_edge_cover` instead.

Type: `CPLib.Bipartite::BipartiteGraphFlow -> Std::Array Std::Bool`

`calc_min_edge_cover`の別名（非推奨）

#### get_min_vertex_cover

**Deprecated**: Use `CPLib.Bipartite::BipartiteGraphFlow::calc_min_vertex_cover` instead.

Type: `CPLib.Bipartite::BipartiteGraphFlow -> (Std::Array Std::Bool, Std::Array Std::Bool)`

`calc_min_vertex_cover`の別名（非推奨）

## Types and aliases

### namespace CPLib.Bipartite

#### BipartiteGraph

Defined as: `type BipartiteGraph = unbox struct { ...fields... }`

二部グラフの型

#### BipartiteGraphFlow

Defined as: `type BipartiteGraphFlow = unbox struct { ...fields... }`

二部グラフに対する最大フロー問題のグラフ

## Traits and aliases

## Trait implementations