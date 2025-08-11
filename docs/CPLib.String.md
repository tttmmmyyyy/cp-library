# CPLib.String

Defined in cp-library@0.5.1

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

Type: `[a : CPLib.String::EmbedToI64] Std::Array Std::I64 -> Std::Array a -> Std::Array Std::I64`

配列のLCP arrayを計算する

##### Returns

長さ`s.get_size - 1`の配列`lcp`で、`lcp.@(i)`は`s[sa.@(i)..)`と`s[sa.@(i+1)..)`の最長共通接頭辞の長さを表す。

##### Parameters

- `sa` : 対象の配列のsuffix array
- `s` : 対象の配列

#### calc_suffix_array

Type: `Std::String -> Std::Array Std::I64`

文字列のsuffix arrayを計算する

注：現在はSA-ISではなくダブリングで実装されているため、計算量はO(n (log n)^2)です。

##### Returns

`[0, 1, ..., s.get_size)` の順列`sa`で、任意の`i`について`s[sa.@(i)..) < s[sa.@(i+1)..)` が成り立つもの

##### Parameters

- `s` : 対象の文字列

#### calc_suffix_array_any

Type: `[a : CPLib.String::EmbedToI64] Std::Array a -> Std::Array Std::I64`

配列のsuffix arrayを計算する

注：現在はSA-ISではなくダブリングで実装されているため、計算量はO(n (log n)^2)です。

##### Returns

`[0, 1, ..., s.get_size)` の順列`sa`で、任意の`i`について`s[sa.@(i)..) < s[sa.@(i+1)..)` が成り立つもの

##### Parameters

- `s` : 対象の配列

### namespace CPLib.String::EmbedToI64

#### embed

Type: `[a : CPLib.String::EmbedToI64] a -> Std::I64`

## Types and aliases

## Traits and aliases

### namespace CPLib.String

#### trait `a : EmbedToI64`

##### method `embed`

Type: `a -> Std::I64`

## Trait implementations

### impl `Std::I16 : CPLib.String::EmbedToI64`

### impl `Std::I32 : CPLib.String::EmbedToI64`

### impl `Std::I64 : CPLib.String::EmbedToI64`

### impl `Std::I8 : CPLib.String::EmbedToI64`

### impl `Std::U16 : CPLib.String::EmbedToI64`

### impl `Std::U32 : CPLib.String::EmbedToI64`

### impl `Std::U8 : CPLib.String::EmbedToI64`