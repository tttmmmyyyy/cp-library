# CPLib.String

Defined in cp-library@0.15.2

文字列と配列の接尾辞・接頭辞を扱うアルゴリズム（suffix array、LCP array、Z-array）

文字列を受ける関数は、文字列をバイトの列として扱います。各関数には、任意の要素型の配列を受ける関数（名前の末尾が`_any`）があります。

`s[i..j)`は`s`の`i`番目から`j - 1`番目までの部分列を表し、`j`を省いた`s[i..)`は`i`番目以降からなる接尾辞を表します。

## Examples

```fix
let s = "abab";
let sa = calc_suffix_array(s); // 接尾辞を辞書順に並べると "ab", "abab", "b", "bab"
assert_eq(|_|"", sa, [2, 0, 3, 1]);;
assert_eq(|_|"", calc_lcp_array(sa, s), [2, 0, 1]);;
assert_eq(|_|"", calc_z_array(s), [4, 0, 2, 0])
```

## Values

### namespace CPLib.String

#### calc_lcp_array

Type: `Std::Array Std::I64 -> Std::String -> Std::Array Std::I64`

文字列のLCP arrayを計算する

制約：saはsのsuffix array, 文字列のバイト数 < 2^31

計算量：O(n)、n = 文字列のバイト数

##### Returns

長さ`max(n - 1, 0)`の配列`lcp`で、`lcp.@(i)`は`s[sa.@(i)..)`と`s[sa.@(i+1)..)`の最長共通接頭辞の長さを表す。

##### Parameters

- `sa` : 対象の文字列のsuffix array
- `s` : 対象の文字列

##### Examples

```fix
let s = "abab";
let sa = calc_suffix_array(s); // 接尾辞を辞書順に並べると "ab", "abab", "b", "bab"
assert_eq(|_|"", sa, [2, 0, 3, 1]);;
assert_eq(|_|"", calc_lcp_array(sa, s), [2, 0, 1])
```

#### calc_lcp_array_any

Type: `[a : Std::Eq] Std::Array Std::I64 -> Std::Array a -> Std::Array Std::I64`

配列のLCP arrayを計算する

制約：saはsのsuffix array, |s| < 2^31

計算量：O(n)、n = |s|

##### Returns

長さ`max(n - 1, 0)`の配列`lcp`で、`lcp.@(i)`は`s[sa.@(i)..)`と`s[sa.@(i+1)..)`の最長共通接頭辞の長さを表す。

##### Parameters

- `sa` : 対象の配列のsuffix array
- `s` : 対象の配列

#### calc_suffix_array

Type: `Std::String -> Std::Array Std::I64`

文字列のsuffix arrayを計算する

AtCoder Libraryの`suffix_array`の移植です。

制約：文字列のバイト数 < 2^31

計算量：O(n)、n = 文字列のバイト数

##### Returns

`[0, 1, ..., n)` の順列`sa`で、0 <= i < n - 1を満たすすべての`i`について`s[sa.@(i)..) < s[sa.@(i+1)..)` が成り立つもの。n = 文字列のバイト数

##### Parameters

- `s` : 対象の文字列

#### calc_suffix_array_any

Type: `[a : Std::Eq, a : Std::LessThan] Std::Array a -> Std::Array Std::I64`

比較できる要素の配列のsuffix arrayを計算する

AtCoder Libraryの`suffix_array`の移植です。要素を座標圧縮し（大小の順に0から番号を振り）、その番号の列のsuffix arrayを求めます。

制約：|s| < 2^31、`<`と`==`が全順序を与える

計算量：O(n log n)、n = |s|。要素の比較をO(1)とする

##### Returns

`[0, 1, ..., n)` の順列`sa`で、0 <= i < n - 1を満たすすべての`i`について`s[sa.@(i)..) < s[sa.@(i+1)..)` が成り立つもの

##### Parameters

- `s` : 対象の配列

##### Examples

```fix
// 接尾辞を辞書順に並べると "ab", "abab", "b", "bab"
assert_eq(|_|"", calc_suffix_array_any(["a", "b", "a", "b"]), [2, 0, 3, 1])
```

#### calc_suffix_array_i64

Type: `Std::Array Std::I64 -> Std::Array Std::I64`

`I64`の配列のsuffix arrayを計算する

`calc_suffix_array_any`と同じ結果を返す。

制約：|s| < 2^31

計算量：O(n log n)、n = |s|

##### Parameters

- `s` : 対象の配列

#### calc_suffix_array_i64_upper

Type: `Std::I64 -> Std::Array Std::I64 -> Std::Array Std::I64`

配列のsuffix arrayを計算する

AtCoder Libraryの`suffix_array`の移植です。

制約：0 <= s.@(i) <= upper < 2^31、|s| < 2^31

計算量：O(n + upper)、n = |s|

##### Returns

`[0, 1, ..., n)` の順列`sa`で、0 <= i < n - 1を満たすすべての`i`について`s[sa.@(i)..) < s[sa.@(i+1)..)` が成り立つもの

##### Parameters

- `upper` : `s`の要素の上限
- `s` : 対象の配列

#### calc_z_array

Type: `Std::String -> Std::Array Std::I64`

文字列のZ-arrayを計算する

計算量：O(n)、n = 文字列のバイト数

##### Returns

長さnの配列`z`で、`z.@(i)`は`s[i..)`と`s`の最長共通接頭辞の長さを表す。n = 文字列のバイト数

##### Parameters

- `s` : 対象の文字列

#### calc_z_array_any

Type: `[a : Std::Eq] Std::Array a -> Std::Array Std::I64`

配列のZ-arrayを計算する

計算量：O(n)、n = |s|

##### Returns

長さnの配列`z`で、`z.@(i)`は`s[i..)`と`s`の最長共通接頭辞の長さを表す。

##### Parameters

- `s` : 対象の配列

## Types and aliases

## Traits and aliases

## Trait implementations