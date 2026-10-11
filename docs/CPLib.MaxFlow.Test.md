# CPLib.MaxFlow.Test

Defined in cp-library@0.15.0

## Values

### namespace CPLib.MaxFlow.Test

#### min_cut_by_brute_force

Type: `Std::I64 -> Std::I64 -> Std::I64 -> Std::Array (Std::I64, Std::I64, Std::I64) -> Std::I64`

頂点の集合ごとのカットの容量を総当たりして、最小カットの容量を求める

#### net_outflow

Type: `Std::I64 -> Std::Array CPLib.MaxFlow::MaxFlowEdge -> Std::Array Std::I64`

頂点ごとの、流れ出す量から流れ込む量を引いた値

#### rand_below

Type: `Std::I64 -> Random::Random -> (Random::Random, Std::I64)`

0以上k未満の乱数

#### reachable_by_brute_force

Type: `Std::I64 -> Std::I64 -> Std::Array (Std::I64, Std::I64, Std::I64) -> Std::Array Std::Bool`

残余容量が正の辺をたどって、頂点sから届く頂点

#### residual_arcs

Type: `Std::Array CPLib.MaxFlow::MaxFlowEdge -> Std::Array (Std::I64, Std::I64, Std::I64)`

辺の状態から、残余グラフの辺を(始点, 終点, 残余容量)の列にする

#### test

Type: `Std::IO ()`

#### test_basic

Type: `Std::IO ()`

#### test_dead_end_speed

Type: `Std::IO ()`

行き止まりの長い鎖に`n`本の並行辺が入るグラフ

行き止まりと分かった頂点を同じフェーズで再び探索すると、`n`本の辺ごとに鎖を辿り直して O(n^2) かかる。

#### test_decrease_capacity

Type: `Std::IO ()`

辺の容量を減らし、はみ出した流れを別の頂点の組で流して直す

0 -> 1 -> 2 -> 3 に容量 2、1 -> 4 -> 2 に容量 1。0 から 3 へ 2 流した後、1 -> 2 の容量を 0 にする。
1 -> 2 に流れていた量を、まず 1 から 2 へ別の道で流し、流せなかった分は 1 から 0 と 3 から 2 へ押し戻す。

#### test_edges

Type: `Std::IO ()`

辺の状態を読み、書き換える

#### test_flow_limit

Type: `Std::IO ()`

流量の上限を指定して流し、続きから流す

#### test_long_path

Type: `Std::IO ()`

長い道のグラフ。頂点数に比例する深さで再帰する実装は、既定のスタックで溢れる

#### test_min_cut_before_and_after_flow

Type: `Std::IO ()`

最小カットは、その時点の残余グラフから求める

#### test_random

Type: `Random::Random -> Std::IO Random::Random`

小さな乱択グラフで、最大流を総当たりの最小カットと比べ、辺の流量と最小カットを確かめる

#### test_random_operations

Type: `Random::Random -> Std::IO Random::Random`

辺を足す、辺を書き換える、最小カットを聞く、開始地点・終了地点・上限を変えて流す、を乱択で混ぜ、
流すたびに、流した量がその時点の残余グラフの最小カット（と上限）に等しく、開始地点と終了地点以外の頂点の差を変えないことを確かめる

## Types and aliases

## Traits and aliases

## Trait implementations