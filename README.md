# cp-library

プログラミング言語Fixで書かれた競技プログラミング用ライブラリです。

## このライブラリの概要

* IO
  * 整数、浮動小数点数、文字列、文字やその配列を空白区切りで読み込むための関数群。
  * Tips:
    * 文字列を1行読み込むときは`Std::IO::input_line_s`を使います。
    * 文字列を文字（`U8`）の配列に変換するときは`get_bytes : String -> Array U8`を使います。ただし、得られる配列はnull終端文字を含みます。
    * バイト配列`Array U8`を文字列に変換するときは`from_bytes(bytes).as_ok` と書きます（`from_bytes`は`FromBytes`トレイトのメンバで、`String`は`FromBytes`トレイトを実装している）。
* Mod Int
  * `CPLib.ZP` : 静的な（すなわち、コンパイル時に決まる）素数を法とする整数の剰余環（体）の演算を提供します。またnumber theoretic transform（NTT）も提供します。
* 整数論
  * `CPLib.ZP.Arithmetic` : mod演算、GCD、拡張ユークリッドの互除法、pow_mod、inv_mod、中国剰余定理、素数リスト（篩）、素数判定（Miller-Rabin法）。
* セグメント木
  * `CPLib.Segtree` : 静的にモノイド構造が決まる場合のセグメント木。
  * `CPLib.DSegtree` : 動的にモノイド構造が決まる場合のセグメント木。
  * `CPLib.LSegtree` : 遅延作用を持つセグメント木（モノイドおよび作用が静的に決まる場合）。
  * `CPLib.LDSegtree` : 遅延作用を持つセグメント木（モノイドおよび作用が動的に決まる場合）。
* Union-Find木
  * `CPLib.UnionFind` : Union-Find木の実装。
* グラフ
  * `CPLib.Graph` : グラフの表現と基本的なアルゴリズム。ダイクストラ法、連結成分分解、トポロジカルソート。
* 畳み込み
  * `CPLib.Convolution` : mod pおよび`I64`の畳み込みの実装。
* トレイト
  * `CPLib.Trait` : モジュールを超えて使われる可能性があるトレイトの定義。Monoid, Actionなど。


## 競技プログラミングで有用な他のライブラリ

それぞれ
```
* project-name
  * module-name
```
という形式で書いています。
`fix deps add {project-name}` して、ソースコード中で`import {module-name}` することで使えるようになります。

* minilib-collection
  * `Minilib.Collection.OrderedMap`
  * `Minilib.Collection.RBTree`
  * `Minilib.Collection.TreeMap`
  * `Minilib.Collection.TreeSet`
* binary-heap
  * `BinaryHeap`: 二分ヒープ（優先順位付きキュー）
* bool-array
  * `BoolArray`: bool型の配列を空間効率良く扱うモジュール
* ring-buffer
  * `RingBuffer`: リングバッファ