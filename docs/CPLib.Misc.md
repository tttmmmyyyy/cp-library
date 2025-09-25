# CPLib.Misc

Defined in cp-library@0.6.7

## Values

### namespace CPLib.Misc

#### next_permutation

Type: `[a : Std::LessThanOrEq] Std::I64 -> Std::I64 -> Std::Array a -> Std::Option (Std::Array a)`

配列のある区間`[begin, end)`を辞書順で次に大きい順列に並び替える。

##### Complexity

- `O(end - begin)`

##### Returns

- 新しい順列`arr`が存在する場合は`some(arr)`、そうでない場合は`none()`

##### Parameters

- `begin`: 区間の開始インデックス
- `end`: 区間の終了インデックス (exclusive)
- `arr`: 配列。`0 <= begin <= end <= |arr|`。

## Types and aliases

## Traits and aliases

## Trait implementations