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

## このライブラリの概要（と競プロTips）

* 入出力・パース
  * （`Std::IO::input_line_s : IO String` で標準入力から1行を文字列として読み込みます。）
  * `CPLib.IO.input_line_i : IO I64` で標準入力から1行を符号付き整数として読み込みます。
  * `CPLib.IO.input_line_u : IO U64` で標準入力から1行を符号なし整数として読み込みます。
  * `CPLib.IO.input_line_ia : IO (Array I64)` で標準入力から1行を整数の配列"x y z"として読み込みます。
  * `CPLib.IO.input_line_uia : IO (Array U64)` で標準入力から1行を符号なし整数の配列"x y z"として読み込みます。
  * `CPLib.IO::stoi : String -> I64`で文字列を符号付き整数に変換できます。
  * `CPLib.IO::stoui : String -> U64`で文字列を符号なし整数に変換できます。
  * `CPLib.IO::stoia : String -> Array I64`で文字列を整数の配列に変換できます。
  * `CPLib.IO::stouia : String -> Array U64`で文字列を符号なし整数の配列に変換できます。
  * 文字列を文字（`U8`）の配列に変換するときは`get_bytes : String -> Array U8`を使います。ただし、得られる配列はnull終端文字を含みます。