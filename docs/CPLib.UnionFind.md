# CPLib.UnionFind

Defined in cp-library@0.15.1

Union-Find木

要素の検索を伴う関数は、パス圧縮で更新したUnionFind木を結果とともに返します。

## Examples

```fix
let uf = create(4).unite(0, 1).unite(1, 2);
let (uf, united) = uf.is_united(0, 2);
assert(|_|"", united);;
let (_, size) = uf.get_group_size(3);
assert_eq(|_|"", size, 1)
```

## Values

### namespace CPLib.UnionFind

#### create

Type: `Std::I64 -> CPLib.UnionFind::UnionFind`

UnionFind木を作成する

`0`から`size - 1`までの`size`個の要素を持つUnionFind木を作成する

制約：0 <= size < 2^31

計算量：O(size)

##### Parameters

- `size` : UnionFind木のサイズ

#### find_parent

**Deprecated**: Use `CPLib.UnionFind::get_leader` instead.

Type: `Std::I64 -> CPLib.UnionFind::UnionFind -> (CPLib.UnionFind::UnionFind, Std::I64)`

`get_leader`の別名（非推奨）

#### get_group_count

Type: `CPLib.UnionFind::UnionFind -> Std::I64`

グループの数を取得する

計算量：O(1)

##### Parameters

- `uf` : UnionFind木

#### get_group_size

Type: `Std::I64 -> CPLib.UnionFind::UnionFind -> (CPLib.UnionFind::UnionFind, Std::I64)`

指定された要素が属するグループのサイズを取得する

パス圧縮を行うため、UnionFindの状態も変化する

制約：0 <= x < size

計算量：ならしO(α(size))

##### Parameters

- `x` : 対象となる要素
- `uf` : UnionFind木

#### get_groups

Type: `CPLib.UnionFind::UnionFind -> (CPLib.UnionFind::UnionFind, Std::Array (Std::Array Std::I64))`

グループの配列を取得する

グループの配列[g0, g1, g2, ...]を返す。各グループの要素は昇順で、グループは最小の要素の昇順に並ぶ。

パス圧縮を行うため、UnionFindの状態も変化する

計算量：O(size α(size))

##### Parameters

- `uf` : UnionFind木

#### get_leader

Type: `Std::I64 -> CPLib.UnionFind::UnionFind -> (CPLib.UnionFind::UnionFind, Std::I64)`

指定された要素の属するグループの代表元を取得する

パス圧縮を行うため、UnionFindの状態も変化する

制約：0 <= x < size

計算量：ならしO(α(size))

##### Parameters

- `x` : 対象となる要素
- `uf` : UnionFind木

#### is_united

Type: `Std::I64 -> Std::I64 -> CPLib.UnionFind::UnionFind -> (CPLib.UnionFind::UnionFind, Std::Bool)`

2つの要素が同じグループに属しているかどうかを判定する

パス圧縮を行うため、UnionFindの状態も変化する

制約：0 <= x, y < size

計算量：ならしO(α(size))

##### Parameters

- `x` : 1つ目の要素
- `y` : 2つ目の要素
- `uf` : UnionFind木

#### try_unite

Type: `Std::I64 -> Std::I64 -> CPLib.UnionFind::UnionFind -> (CPLib.UnionFind::UnionFind, Std::Bool)`

2つの要素を同じグループにし、2つが別のグループだったかを返す

別のグループだったなら併合して`true`を、すでに同じグループに属しているなら何もせず`false`を返す。

制約：0 <= x, y < size

計算量：ならしO(α(size))

##### Parameters

- `x` : 1つ目の要素
- `y` : 2つ目の要素
- `uf` : UnionFind木

##### Examples

```fix
// クラスカル法：別のグループを結ぶ辺だけを採る
let (uf, taken) = [(0, 1), (1, 2), (0, 2)].to_iter.fold((create(3), []), |(x, y), (uf, taken)|
    let (uf, merged) = uf.try_unite(x, y);
    (uf, taken.push_back(merged))
);
assert_eq(|_|"", taken, [true, true, false])
```

#### unite

Type: `Std::I64 -> Std::I64 -> CPLib.UnionFind::UnionFind -> CPLib.UnionFind::UnionFind`

2つの要素を同じグループにする

すでに同じグループに属しているなら何もしない。

制約：0 <= x, y < size

計算量：ならしO(α(size))

##### Parameters

- `x` : 1つ目の要素
- `y` : 2つ目の要素
- `uf` : UnionFind木

## Types and aliases

### namespace CPLib.UnionFind

#### UnionFind

Defined as: `type UnionFind = unbox struct { ...fields... }`

## Traits and aliases

## Trait implementations