# CPLib.Graph

Defined in cp-library@0.15.0

グラフの表現と基本的なアルゴリズム

グラフは、`GraphBuilder`に辺を足していき、`build`で`Graph`にしてから使います。

制約・計算量の n は頂点数、m は辺数を表します。

## Examples

```fix
// 辺のデータをコストとして、ダイクストラ法で最短距離を求める
let g = GraphBuilder::create(3).add_edge(0, 1, 5).add_edge(1, 2, 2).add_edge(0, 2, 10).build;
assert_eq(|_|"", g.dijkstra(0), [0, 5, 7])
```

## Values

### namespace CPLib.Graph

#### @size

Type: `CPLib.Graph::Graph c -> Std::I64`

グラフの頂点数を取得する

計算量：O(1)

##### Parameters

- `graph` : グラフ

#### bellman_ford

Type: `[c : CPLib.Trait::Inf, c : Std::Additive, c : Std::Eq, c : Std::LessThan] Std::I64 -> CPLib.Graph::Graph c -> Std::Array c`

ベルマンフォード法：グラフと開始ノードが与えられたとき、開始ノードから各ノードに到達するまでの最小コストの配列を返す。

到達できないノードまでの距離には`Inf::inf`が設定されます。

制約：0 <= start < n, 開始ノードから到達できる負の閉路がない

計算量：O(n (n + m))

##### Parameters

- `start` : 開始ノードの番号
- `graph` : グラフ

#### calc_scc_ids

Type: `CPLib.Graph::Graph c -> (Std::I64, Std::Array Std::I64)`

頂点ごとに、その頂点を含む強連結成分の番号を求める

戻り値は、強連結成分の数`num`と、長さが頂点数の配列`ids`の組。
番号は0以上`num`未満で、トポロジカル順に振られる：uとvが異なる強連結成分に属するとき、uからvに到達できるなら、`ids.@(u) < ids.@(v)`。
番号`c`の強連結成分は、`calc_sccs`の戻り値の`c`番目の要素である。

計算量：O(n + m)

##### Parameters

- `g` : グラフ

##### Examples

```fix
// 0 -> 1 -> 2 -> 1、2 -> 3。{1, 2}が1つの強連結成分になる
let g = GraphBuilder::create(4).add_edge(0, 1, ()).add_edge(1, 2, ()).add_edge(2, 1, ()).add_edge(2, 3, ()).build;
assert_eq(|_|"", g.calc_scc_ids, (3, [0, 1, 1, 2]))
```

#### calc_sccs

Type: `CPLib.Graph::Graph c -> Std::Array (Std::Array Std::I64)`

グラフの強連結成分分解を求める

戻り値は、各強連結成分を構成する頂点のリストの配列です。
また、戻り値はトポロジカルソートされています：uとvが異なる強連結成分cu, cvに属するとき、uからvに到達できるなら、cuはcvの前に現れます。

計算量：O(n + m)

##### Parameters

- `g` : グラフ

#### dijkstra

Type: `[c : CPLib.Trait::Inf, c : Std::Additive, c : Std::LessThan] Std::I64 -> CPLib.Graph::Graph c -> Std::Array c`

ダイクストラ法：グラフと開始ノードが与えられたとき、開始ノードから各ノードに到達するまでの最小コストの配列を返す。

到達できないノードまでの距離には`Inf::inf`が設定されます。

制約：0 <= start < n, 辺のコスト >= 0

計算量：O((n + m) log m)

##### Parameters

- `start` : 開始ノードの番号
- `graph` : グラフ

#### get_out_degree

Type: `Std::I64 -> CPLib.Graph::Graph c -> Std::I64`

頂点`v`から出る辺の本数を取得する

制約：0 <= v < n

計算量：O(1)

##### Parameters

- `v` : 始点の頂点番号
- `graph` : グラフ

#### get_size

**Deprecated**: Use `CPLib.Graph::@size` instead.

Type: `CPLib.Graph::Graph c -> Std::I64`

`@size`の別名（非推奨）

#### reverse

Type: `CPLib.Graph::Graph c -> CPLib.Graph::Graph c`

すべての辺の向きを逆にしたグラフを作る

元のグラフの辺u -> vは、データを引き継いで辺v -> uになる。

計算量：O(n + m)

##### Parameters

- `graph` : グラフ

##### Examples

```fix
// 0 -> 1 -> 2、0 -> 2。逆にすると、2から1と0へ、1から0へ辺が出る
let g = GraphBuilder::create(3).add_edge(0, 1, "a").add_edge(1, 2, "b").add_edge(0, 2, "c").build;
let rg = g.reverse;
assert_eq(|_|"", rg.get_out_degree(2), 2);;
assert_eq(|_|"", rg.to_iter_edges(1).map(|Edge { to, data }| (to, data)).to_array, [(0, "a")])
```

#### to_iter_edges

Type: `[?it : Std::Iterator, Std::Iterator::Item ?it = CPLib.Graph::Edge c] Std::I64 -> CPLib.Graph::Graph c -> ?it`

頂点`v`から出る辺を返すイテレータを作る

制約：0 <= v < n

計算量：O(1)

##### Parameters

- `v` : 始点の頂点番号
- `graph` : グラフ

### namespace CPLib.Graph::Edge

#### make

Type: `Std::I64 -> c -> CPLib.Graph::Edge c`

辺を作成する

### namespace CPLib.Graph::GraphBuilder

#### add_edge

Type: `Std::I64 -> Std::I64 -> c -> CPLib.Graph::GraphBuilder c -> CPLib.Graph::GraphBuilder c`

グラフに辺を追加する

制約：0 <= from, to < n

計算量：ならしO(1)

##### Parameters

- `from` : 始点の頂点番号
- `to` : 終点の頂点番号
- `data` : 辺のデータ
- `builder` : 辺を足していく途中のグラフ

#### build

Type: `CPLib.Graph::GraphBuilder c -> CPLib.Graph::Graph c`

辺を足し終えたグラフを作る

制約：m < 2^31

計算量：O(n + m)

##### Parameters

- `builder` : 辺を足していく途中のグラフ

#### create

Type: `Std::I64 -> CPLib.Graph::GraphBuilder c`

頂点数が`n`で辺のない`GraphBuilder`を作成する

制約：0 <= n < 2^31

計算量：O(1)

##### Parameters

- `n` : 頂点数

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

#### Graph

Defined as: `type Graph c = unbox struct { ...fields... }`

辺を足し終えたグラフ

`GraphBuilder::build`で作ります。型パラメータ`c`は辺に付随するデータの型です。

#### GraphBuilder

Defined as: `type GraphBuilder c = unbox struct { ...fields... }`

辺を足していく途中のグラフ

型パラメータ`c`は辺に付随するデータの型です（例：ダイクストラ法に使うときはコスト）。不要な場合はユニット型`()`を指定するとメモリの節約になります。

## Traits and aliases

## Trait implementations