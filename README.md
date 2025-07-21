# cp-library

プログラミング言語Fixで書かれた競技プログラミング用ライブラリです。
    
## ルール

* 各モジュール名は`CPLib.{サブモジュール名}`とします。例：`CPLib.Graph`。
* ドキュメントやコメントは現時点では日本語で書くものとします（開発速度を上げるため。いずれ英訳したいと思っています）。
* 関数ドキュメントには #Parameters セクションを置いてください。
* すべてのコードのライセンスはMITライセンスとします。
* サブモジュール名ごとにフォルダを作ってください（例：`CPLib.IO`モジュールは"io/io.fix"で定義）。
* サブモジュールのフォルダごとにテスト用のモジュール（例：`CPLib.IO.Test`）を作成し、ルートの"test.fix"から呼び出してください。
* "fix docs"で適宜ドキュメントを更新してください。

## このライブラリの概要

* 入出力・パース
  * （`Std::IO::input_line_s : IO String` で標準入力から1行を文字列として読み込みます。）
  * `CPLib.IO.input_line_i : IO I64` で標準入力から1行を符号付き整数として読み込みます。
  * `CPLib.IO.input_line_ui : IO U64` で標準入力から1行を符号なし整数として読み込みます。
  * `CPLib.IO.input_line_f : IO F64` で標準入力から1行を浮動小数点数として読み込みます。
  * `CPLib.IO.input_line_ia : IO (Array I64)` で標準入力から1行を整数の配列"x y z"として読み込みます。
  * `CPLib.IO.input_line_uia : IO (Array U64)` で標準入力から1行を符号なし整数の配列"x y z"として読み込みます。
  * `CPLib.IO.input_line_fa : IO (Array F64)` で標準入力から1行を浮動小数点数の配列"x y z"として読み込みます。
  * `CPLib.IO::stoi : String -> I64`で文字列を符号付き整数に変換できます。
  * `CPLib.IO::stoui : String -> U64`で文字列を符号なし整数に変換できます。
  * `CPLib.IO::stof : String -> F64`で文字列を浮動小数点数に変換できます。
  * `CPLib.IO::stoia : String -> Array I64`で文字列を整数の配列に変換できます。
  * `CPLib.IO::stouia : String -> Array U64`で文字列を符号なし整数の配列に変換できます。
  * `CPLib.IO::stofa : String -> Array F64`で文字列を浮動小数点数の配列に変換できます。
  * 文字列を文字（`U8`）の配列に変換するときは`get_bytes : String -> Array U8`を使います。ただし、得られる配列はnull終端文字を含みます。
    * なお、バイト配列`Array U8`を文字列に変換するときは`from_bytes(bytes).as_ok` と書きます（`from_bytes`は`FromBytes`トレイトのメンバで、`String`は`FromBytes`トレイトを実装している）。
* Mod Int
  * `CPLib.ZP` : 静的な（すなわち、コンパイル時に決まる）素数を法とする整数の剰余環（体）の演算を提供します。
* 整数論
  * `CPLib.ZP.Arithmetic` : GCD, 拡張ユークリッドの互除法, pow_mod, inv_modなど。
* セグメント木
  * `CPLib.Segtree` : 静的にモノイド構造が決まる場合のセグメント木。
  * `CPLib.DSegtree` : 動的にモノイド構造が決まる場合のセグメント木。
  * `CPLib.LSegtree` : 遅延作用を持つセグメント木（モノイドおよび作用が静的に決まる場合）。
  * `CPLib.LDSegtree` : 遅延作用を持つセグメント木（モノイドおよび作用が動的に決まる場合）。
* トレイト
  * `CPLib.Trait` : 複数のモジュールで使われる可能性があるトレイトの定義。Monoid, Actionなど。

## 競技プログラミングで有用な他のライブラリ

それぞれ
```
* project-name
  * module-name
```
という形式で書いています。
`fix deps add {project-name}` して、ソースコード中で`import {module-name}` することで使えるようになります。

* minilib-collection
  * `Minilib.Collection.Deque`
  * `Minilib.Collection.OrderedMap`
  * `Minilib.Collection.RBTree`
  * `Minilib.Collection.TreeMap`
  * `Minilib.Collection.TreeSet`
* binary-heap
  * `BinaryHeap`: 二分ヒープ（優先順位付きキュー）
* bool-array
  * `BoolArray`: bool型の配列を空間効率良く扱うモジュール