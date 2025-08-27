# CPLib.TwoSat

Defined in cp-library@0.6.4

## Values

### namespace CPLib.TwoSat

#### add_clause

Type: `Std::I64 -> Std::Bool -> Std::I64 -> Std::Bool -> CPLib.TwoSat::TwoSat -> CPLib.TwoSat::TwoSat`

節 (a = f) or (b = g) を追加する

##### Parameters

- `a` : 変数1のインデックス
- `f` : 変数1の値（true/false）
- `b` : 変数2のインデックス
- `g` : 変数2の値（true/false）
- `sat` : 2-SAT問題

#### create

Type: `Std::I64 -> CPLib.TwoSat::TwoSat`

2-SAT問題を作る

##### Parameters

- `n` : 変数の数

#### solve

Type: `CPLib.TwoSat::TwoSat -> Std::Option (Std::Array Std::Bool)`

2-SAT問題を解く

##### Returns

充足不能な場合は`none()`。充足可能な場合は`some(arr)`を返す。`arr.@(i)`は各リテラルの真偽値を表す。

##### Parameters

- `sat` : 2-SAT問題

## Types and aliases

### namespace CPLib.TwoSat

#### TwoSat

Defined as: `type TwoSat = unbox struct { ...fields... }`

2-SAT問題の型

##### field `n`

Type: `Std::I64`

変数の数

##### field `graph`

Type: `CPLib.Graph::Graph ()`

グラフ

## Traits and aliases

## Trait implementations