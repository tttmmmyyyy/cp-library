# CPLib.IO

Defined in cp-library@0.2.0

入出力や数値のパースを楽にする機能のためのモジュール

## Values

### namespace CPLib.IO

#### read_c

Type: `Std::IO Std::U8`

非空白文字を一つ読み込む

#### read_cs

Type: `Std::I64 -> Std::IO (Std::Array Std::U8)`

非空白文字を指定された個数読み込む

##### Parameters

- `n`: 読み込む個数

#### read_f

Type: `Std::IO Std::F64`

`F64`を一つ読み込む

#### read_fs

Type: `Std::I64 -> Std::IO (Std::Array Std::F64)`

`F64`を指定された個数読み込む

##### Parameters

- `n`: 読み込む個数

#### read_i

Type: `Std::IO Std::I64`

`I64`を一つ読み込む

#### read_is

Type: `Std::I64 -> Std::IO (Std::Array Std::I64)`

`I64`を指定された個数読み込む

##### Parameters

- `n`: 読み込む個数

#### read_s

Type: `Std::I64 -> Std::IO Std::String`

空白文字を含まない文字列を一つ読み込む

##### Parameters

- `n`: 読み込む文字列の長さの上限

#### read_ss

Type: `Std::I64 -> Std::I64 -> Std::IO (Std::Array Std::String)`

空白文字を含まない文字列を指定された個数読み込む

##### Parameters

- `n`: 読み込む個数
- `m`: 各文字列の長さの上限

#### read_u

Type: `Std::IO Std::U64`

`U64`を一つ読み込む

#### read_us

Type: `Std::I64 -> Std::IO (Std::Array Std::U64)`

`U64`を指定された個数読み込む

##### Parameters

- `n`: 読み込む個数

#### stof

Type: `Std::String -> Std::F64`

文字列をパースして`F64`整数に変換する

##### Parameters

- `s`: 変換したい文字列

#### stofa

Type: `Std::String -> Std::Array Std::F64`

"X Y Z"というフォーマットの文字列をパースして`F64`の配列`[X, Y, Z]`に変換する。

"stofa" = "String TO Float Array"

##### Parameters

- `s`: 変換したい文字列

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