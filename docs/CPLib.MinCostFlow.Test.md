# CPLib.MinCostFlow.Test

Defined in cp-library@0.15.0

## Values

### namespace CPLib.MinCostFlow.Test

#### min_costs_by_brute_force

Type: `Std::I64 -> Std::I64 -> Std::I64 -> Std::Array (Std::I64, Std::I64, Std::I64, Std::I64) -> Std::Array (Std::Option Std::I64)`

各辺の流量を総当たりして、流量ごとの最小コストを求める

戻り値の`f`番目の要素は流量`f`の最小コスト。流量`f`を流せないときは`none()`。

##### Parameters

- `n` : 頂点数
- `s` : 開始頂点番号
- `t` : 終了頂点番号
- `edges` : 辺 (始点, 終点, 容量, コスト) の配列

#### test

Type: `Std::IO ()`

#### test_basic

Type: `Std::IO ()`

#### test_random

Type: `Std::Bool -> Random::Random -> Std::IO Random::Random`

小さな乱択グラフで、総当たりと流量・コストを比べる

流量の上限を変えて`maximize_flow_min_cost`を2回続けて呼び、それぞれを比べる。

##### Parameters

- `negative` : 負のコストの辺を含め、`set_potential_bf`を呼ぶかどうか
- `rng` : 乱数生成器

#### test_unreachable

Type: `Std::IO ()`

sから到達できない頂点があるグラフで、増加路を2本流す

## Types and aliases

## Traits and aliases

## Trait implementations