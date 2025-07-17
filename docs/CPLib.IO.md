# CPLib.IO

Defined in cp-library@0.1.0

入出力や数値のパースを楽にする機能のためのモジュール

## Values

### namespace CPLib.IO

#### input_line_i

Type: `Std::IO Std::I64`

標準入力から1行読み込み、`I64`として返す。

#### input_line_ia

Type: `Std::IO (Std::Array Std::I64)`

"X Y Z"というフォーマットの行を標準入力から読み込み、`I64`の配列`[X, Y, Z]`として返す。

#### input_line_u

Type: `Std::IO Std::U64`

標準入力から1行読み込み、`U64`として返す。

#### input_line_uia

Type: `Std::IO (Std::Array Std::U64)`

"X Y Z"というフォーマットの行を標準入力から読み込み、`U64`の配列`[X, Y, Z]`として返す。

#### stoi

Type: `Std::String -> Std::I64`

文字列をパースして`I64`整数に変換する

##### Parameters

- `s`: 変換したい文字列

#### stoia

Type: `Std::String -> Std::Array Std::I64`

"X Y Z"というフォーマットの文字列をパースして`I64`の配列`[X, Y, Z]`に変換する。

"stoia" = "String TO Integer Array"

##### Parameters

- `s`: 変換したい文字列

#### stoui

Type: `Std::String -> Std::U64`

文字列をパースして`U64`整数に変換する

##### Parameters

- `s`: 変換したい文字列

#### stouia

Type: `Std::String -> Std::Array Std::U64`

"X Y Z"というフォーマットの文字列をパースして`U64`の配列`[X, Y, Z]`に変換する。

"stouia" = "String TO Unsigned Integer Array"

##### Parameters

- `s`: 変換したい文字列

## Types and aliases

## Traits and aliases

## Trait implementations