# CPLib.Misc

Defined in cp-library@0.15.0

## Values

### namespace CPLib.Misc

#### next_permutation

Type: `[a : Std::LessThanOrEq] Std::I64 -> Std::I64 -> Std::Array a -> Std::Option (Std::Array a)`

配列のある区間`[begin, end)`を辞書順で次に大きい順列に並び替える。

制約：0 <= begin <= end <= |arr|

計算量：O(end - begin)

##### Returns

- 新しい順列`arr`が存在する場合は`some(arr)`、そうでない場合は`none()`

##### Parameters

- `begin`: 区間の開始インデックス
- `end`: 区間の終了インデックス (exclusive)
- `arr`: 配列

##### Examples

```fix
assert_eq(|_|"", [1, 2, 3].next_permutation(0, 3), some([1, 3, 2]));;
assert_eq(|_|"", [3, 2, 1].next_permutation(0, 3), none())
```

## Types and aliases

## Traits and aliases

## Trait implementations