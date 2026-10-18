# cp-library

プログラミング言語Fixで書かれた競技プログラミング用ライブラリです。

## このライブラリの概要

* IO
  * 整数、浮動小数点数、文字列、文字やその配列を空白区切りで読み込むための関数群。
  * Tips:
    * 空白を含む行を読み込みたいときは`Std::IO::input_line_s`を使います。ただし`CPLib.IO`の諸関数（`read_i`など）は字句の直後の改行文字を読まずに残すため、`read_i`のあとに`input_line_s`を使う場合には要注意です：`read_i`が読まずに残している改行文字を`input_line_s`が読み込んでしまう場合があります。このような場合は`input_line_s`を一度余分に呼び出して改行文字を読み飛ばす必要があります。
    * 文字列を文字（`U8`）の配列に変換するときは`get_bytes : String -> Array U8`を使います。ただし、得られる配列はnull終端文字を含みます。
    * バイト配列`Array U8`を文字列に変換するときは`from_bytes(bytes).as_ok` と書きます（`from_bytes`は`FromBytes`トレイトのメンバで、`String`は`FromBytes`トレイトを実装している）。
* Mod Int
  * `CPLib.ZP` : 静的な（すなわち、コンパイル時に決まる）素数を法とする整数の剰余環（体）の演算を提供します。またnumber theoretic transform（NTT）も提供します。
* 整数論
  * `CPLib.Arithmetic` : mod演算、整数の平方根、べき乗、GCD、拡張ユークリッドの互除法、pow_mod、inv_mod、中国剰余定理、素数リスト（篩）、素因数分解、素数判定（Miller-Rabin法）、オイラーのトーシェント関数、原始根、floor_sum、ピタゴラス数
* セグメント木
  * `CPLib.Segtree` : 静的にモノイド構造が決まる場合のセグメント木。
  * `CPLib.DSegtree` : 動的にモノイド構造が決まる場合のセグメント木。
  * `CPLib.LSegtree` : 遅延作用を持つセグメント木（モノイドおよび作用が静的に決まる場合）。
  * `CPLib.LDSegtree` : 遅延作用を持つセグメント木（モノイドおよび作用が動的に決まる場合）。
  * `CPLib.Monoid` : セグメント木でよく使うモノイド（和、積、最小値、最大値、重みつきの和）と作用（区間加算、区間乗算、区間代入、アフィン変換）。
* Union-Find木
  * `CPLib.UnionFind` : Union-Find木の実装。
* フロー・最小カット・二部グラフ
  * `CPLib.MaxFlow` : 最大フロー・最小カット（Dinic法）
  * `CPLib.MinCostFlow` : 最小費用流、流量ごとの最小コスト（slope）。
  * `CPLib.Bipartite` : 二部グラフの最大マッチング、最小辺被覆、最大独立集合、最小点被覆。
* 文字列
  * `CPLib.String` : Suffix Array、LCP Array、Z Algorithm。
* グラフ
  * `CPLib.Graph` : グラフの表現と基本的なアルゴリズム。ダイクストラ法、ベルマンフォード法、強連結成分分解（成分をトポロジカル順に返す）。
* 2Sat
  * `CPLib.TwoSat` : 2-SAT問題
* 畳み込み
  * `CPLib.Convolution` : mod pおよび`I64`の畳み込みの実装。
* トレイト
  * `CPLib.Trait` : モジュールを超えて使われる可能性があるトレイトの定義。Monoid, Actionなど。
* ビット操作
  * `CPLib.Bits` : `I64`のビット操作に関するユーティリティ。ビット列としての文字列化、ビットのチェック、セット、クリア、フリップ、組み合わせ列挙、部分集合列挙、popcount。
* そのほか
  * `CPLib.Misc` : next_permutation。
  * `CPLib.Memoize` : メモ化モナドの実装。ハッシュマップや配列をメモリ領域として利用可能。

## 性能

[AtCoder Library](https://github.com/atcoder/ac-library)（C++）と遜色ない速さで動きます。cp-libraryとAtCoder Libraryの性能比較は[Fixのベンチマーク](https://tttmmmyyyy.github.io/fixlang/benchmark/)で見られます。

## 関数の名前

値を返す関数の名前は、次の決まりで先頭の動詞を選んでいます。ただし、Fixの標準ライブラリや競技プログラミングで広く使われている名前があるものは、その名前を使います（例：`fold`、`pow_mod`、`floor_sum`、`dijkstra`）。

* `get_X`：軽い処理。計算量が、出力の大きさに比例する程度か、それ以下のもの。ただしα(n)は定数と同程度と扱います。
   * 例：`get_edge`（O(1)）、`get_group_size`（ならしO(α(n))）、`get_edges`（O(m)、出力の大きさm）、`get_groups`（O(n α(n))、出力の大きさn）
* `calc_X`：重い処理。計算量が、出力の大きさを超えるもの。
   * 例：`calc_gcd`、`calc_suffix_array`、`calc_sccs`（O(n + m)、出力の大きさn）、`calc_min_cut`（O(n + m)、出力の大きさn）
* データ構造の中身を変えることが目的の関数は、処理に対応した動詞で始めます。
   * 例：`maximize_flow`、`add_edge`、`create`
* 真偽値を返す関数は`is_X`です。
   * 例：`is_prime`、`is_united`

## 注意

* （2026-10-18時点）AtCoderのジャッジに入っているのは、Fix 1.1.0（言語の一覧での表示は`Fix (1.1.0-alpha.12)`）とcp-library 0.6.6です。その後、コンパイラにもcp-libraryにも、大幅な性能向上と、一部の互換性のない変更が入っています。
* cp-libraryの関数は、既定では添字の範囲などの引数の制約を検査し、満たさなければ理由を標準エラーに書いてプログラムを止めます。Fixのコンパイラも、配列の範囲外アクセスなどを検査するコードを入れます。これらの検査を省いて速く動かしたいときは、`fix build`に`--no-runtime-check`を付けてください。その場合、制約を満たさない引数を渡したときの動作は未定義になります。今後、競技プログラミングのジャッジにFixを登録するときは、コンパイルのコマンドに`--no-runtime-check`を付ける予定です。
* 再帰が深くなるプログラムは、既定のスタック上限ではスタックオーバーフローする場合があります。その場合は`ulimit -s unlimited`としてから実行してください（AtCoderのジャッジでも同様の設定です）。

## 競技プログラミングで有用な他のライブラリ

それぞれ
```
* project-name
  * module-name
```
という形式で書いています。
`fix deps add {project-name}` して、ソースコード中で`import {module-name};` することで使えるようになります。

* minilib-collection
  * `Minilib.Collection.OrderedMap`
  * `Minilib.Collection.TreeMap`
  * `Minilib.Collection.TreeSet`
* binary-heap
  * `BinaryHeap`: 二分ヒープ（優先順位付きキュー）
* bool-array
  * `BoolArray`: bool型の配列を空間効率良く扱うモジュール
* ring-buffer
  * `RingBuffer`: リングバッファ
* gmp-fix
  * `GMP.Z`: 任意精度の整数型 `MPZ`
  * `GMP.Q`: 任意精度の有理数型 `MPQ`