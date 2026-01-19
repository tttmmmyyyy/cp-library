# CPLib.String

Defined in cp-library@0.7.5

## Values

### namespace CPLib.String

#### calc_lcp_array

Type: `Std::Array Std::I64 -> Std::String -> Std::Array Std::I64`

文字列のLCP arrayを計算する

##### Returns

長さ`s.get_size - 1`の配列`lcp`で、`lcp.@(i)`は`s[sa.@(i)..)`と`s[sa.@(i+1)..)`の最長共通接頭辞の長さを表す。

##### Parameters

- `sa` : 対象の文字列のsuffix array
- `s` : 対象の文字列

#### calc_lcp_array_any

Type: `[a : Std::Eq] Std::Array Std::I64 -> Std::Array a -> Std::Array Std::I64`

配列のLCP arrayを計算する

##### Returns

長さ`s.get_size - 1`の配列`lcp`で、`lcp.@(i)`は`s[sa.@(i)..)`と`s[sa.@(i+1)..)`の最長共通接頭辞の長さを表す。

##### Parameters

- `sa` : 対象の配列のsuffix array
- `s` : 対象の配列

#### calc_suffix_array

Type: `Std::String -> Std::Array Std::I64`

文字列のsuffix arrayを計算する

AtCoder Libraryの`suffix_array`の移植です。

##### Returns

`[0, 1, ..., s.get_size)` の順列`sa`で、任意の`i`について`s[sa.@(i)..) < s[sa.@(i+1)..)` が成り立つもの

##### Parameters

- `s` : 対象の文字列

#### calc_suffix_array_i64

Type: `Std::Array Std::I64 -> Std::Array Std::I64`

配列のsuffix arrayを計算する

AtCoder Libraryの`suffix_array`の移植です。

##### Returns

`[0, 1, ..., s.get_size)` の順列`sa`で、任意の`i`について`s[sa.@(i)..) < s[sa.@(i+1)..)` が成り立つもの

##### Parameters

- `s` : 対象の配列

#### calc_suffix_array_i64_upper

Type: `Std::I64 -> Std::Array Std::I64 -> Std::Array Std::I64`

配列のsuffix arrayを計算する

AtCoder Libraryの`suffix_array`の移植です。

##### Returns

`[0, 1, ..., s.get_size)` の順列`sa`で、任意の`i`について`s[sa.@(i)..) < s[sa.@(i+1)..)` が成り立つもの

##### Parameters

- `s` : 対象の配列

#### calc_z_array

Type: `Std::String -> Std::Array Std::I64`

文字列のZ-arrayを計算する

##### Returns

長さ`s.get_size`の配列`z`で、`z.@(i)`は`s[i..)`と`s.[0..)`の最長共通接頭辞の長さを表す。

##### Parameters

- `s` : 対象の文字列

#### calc_z_array_any

Type: `[a : Std::Eq] Std::Array a -> Std::Array Std::I64`

配列のZ-arrayを計算する

##### Returns

長さ`s.get_size`の配列`z`で、`z.@(i)`は`s[i..)`と`s.[0..)`の最長共通接頭辞の長さを表す。

##### Parameters

- `s` : 対象の配列

## Types and aliases

## Traits and aliases

## Trait implementations