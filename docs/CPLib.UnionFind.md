# CPLib.UnionFind

Defined in cp-library@0.6.4

## Values

### namespace CPLib.UnionFind

#### create

Type: `Std::I64 -> CPLib.UnionFind::UnionFind`

UnionFind木を作成する

`0`から`size - 1`までの`size`個の要素を持つUnionFind木を作成する

##### Parameters

- `size` : UnionFind木のサイズ

#### get_groups

Type: `CPLib.UnionFind::UnionFind -> (CPLib.UnionFind::UnionFind, Std::Array (Std::Array Std::I64))`

グループの配列を取得する

グループの配列[g0, g1, g2, ...]を返す

パス圧縮を行うため、UnionFindの状態も変化する

##### Parameters

- `uf` : UnionFind木

#### is_united

Type: `Std::I64 -> Std::I64 -> CPLib.UnionFind::UnionFind -> (CPLib.UnionFind::UnionFind, Std::Bool)`

2つの要素が同じグループに属しているかどうかを判定する

パス圧縮を行うため、UnionFindの状態も変化する

##### Parameters

- `x` : 1つ目の要素
- `y` : 2つ目の要素
- `uf` : UnionFind木

#### unite

Type: `Std::I64 -> Std::I64 -> CPLib.UnionFind::UnionFind -> CPLib.UnionFind::UnionFind`

2つの要素を同じグループにする

##### Parameters

- `x` : 1つ目の要素
- `y` : 2つ目の要素
- `uf` : UnionFind木

## Types and aliases

### namespace CPLib.UnionFind

#### UnionFind

Defined as: `type UnionFind = unbox struct { ...fields... }`

##### field `parent`

Type: `Std::Array Std::I64`

##### field `rank`

Type: `Std::Array Std::I64`

## Traits and aliases

## Trait implementations