# CPLib.TwoSat

Defined in cp-library@0.14.0

2-SAT問題

制約・計算量の n は変数の数、m は節の数を表します。

## Examples

```fix
// 節 (x0 = true) or (x0 = true)（すなわち x0 = true）と、節 (x0 = false) or (x1 = true) を追加して解く
let sat = create(2).add_clause(0, true, 0, true).add_clause(0, false, 1, true);
assert_eq(|_|"", sat.solve, some([true, true]))
```

## Values

### namespace CPLib.TwoSat

#### add_clause

Type: `Std::I64 -> Std::Bool -> Std::I64 -> Std::Bool -> CPLib.TwoSat::TwoSat -> CPLib.TwoSat::TwoSat`

節 (a = f) or (b = g) を追加する

制約：0 <= a, b < n

計算量：ならしO(1)

##### Parameters

- `a` : 変数1のインデックス
- `f` : 変数1の値（true/false）
- `b` : 変数2のインデックス
- `g` : 変数2の値（true/false）
- `sat` : 2-SAT問題

#### create

Type: `Std::I64 -> CPLib.TwoSat::TwoSat`

2-SAT問題を作る

計算量：O(n)

##### Parameters

- `n` : 変数の数

#### solve

Type: `CPLib.TwoSat::TwoSat -> Std::Option (Std::Array Std::Bool)`

2-SAT問題を解く

計算量：O(n + m)

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