# CPLib.Monoid

Defined in cp-library@0.15.2

セグメント木でよく使うモノイドと作用を提供するモジュール。

`CPLib.Segtree`と`CPLib.LSegtree`は、モノイドの型（`Monoid`トレイトを実装した型）と作用の型（`Action`トレイトを実装した型）を要求します。
自作の型に`Monoid`トレイトや`Action`トレイトを実装して使うこともできます（書き方の例は`CPLib.Segtree`と`CPLib.LSegtree`のモジュールの説明にあります）。
このモジュールは、競技プログラミングでよく使うモノイドと作用の型を用意し、`Monoid`トレイトと`Action`トレイトを実装しています。

モノイドは`Sum e`、`Product e`、`Min e`、`Max e`、`WeightedSum e`です。
`e`は`I64`や`F64`などの要素の型で、それぞれのモノイドが必要とする演算のトレイト（`Add`、`Mul`、`LessThan`など）と単位元のトレイト（`Zero`、`One`、`Inf`、`NegInf`など）を実装している必要があります。
モノイドの値はフィールド`v`に入れます（`WeightedSum`は`v`と`w`の2つ）。
たとえば`Max I64`の値は`Max { v : 3 }`で作り、`x.@v`で取り出します。

`WeightedSum e`は`e`型の値2つ（フィールド`v`と`w`）の組で、`op((v1, w1), (v2, w2)) = (v1 + v2, w1 + w2)`と定義されています。
典型的には、`LSegtree`で和のモノイドを扱うときに使います。
このとき`w`はノードが受け持つ区間の長さ（葉では1）を表し、区間への作用を計算するのに使われます。

作用は`RangeAdd m e`、`RangeMul m e`、`RangeAssign m e`、`RangeAffine m e`です。
`m`は作用を受けるモノイドの型コンストラクタ（`Max e`ではなく`Max`）で、`e`はモノイドの要素の型です。

利用できるモノイドと作用の組み合わせと、作用の内容は次のとおりです。

| 作用 | `Sum { v }` | `Min / Max { v }` | `WeightedSum { v, w }` |
| --- | --- | --- | --- |
| `RangeAdd { a }` | なし | `v + a` | `(v + w a, w)` |
| `RangeMul { a }` | `a v` | `a v`（`a >= 0`） | `(a v, w)` |
| `RangeAssign { a }` | なし | `a` | `(w a, w)` |
| `RangeAffine { a, b }` | なし | `a v + b`（`a >= 0`） | `(a v + b w, w)` |

表のセルは、作用を受けた後の値です（`WeightedSum`は`(v, w)`の組）。
`RangeAssign`のフィールド`a`は`Option e`で、`some(c)`なら`c`を代入し、`none()`なら何もしません。

モノイドや作用の計算には、オーバーフローを防ぐ仕組みはありません。
特に、`Min` / `Max`を使うセグメント木を`create`で作ると、すべての要素が`inf`（`Max`では`neg_inf`）で初期化されます。この状態では、作用によって整数はオーバーフローしやすく、浮動小数は0を掛けるとNaNになることに注意してください。

これらのモノイドや作用でセグメント木を作るときは、次のように型注釈でモノイドと作用を指定します。

```fix
import CPLib.LSegtree;
import CPLib.Monoid;
import CPLib.Segtree;
let segtree = Segtree::build([1, 2, 3].map(|v| Max { v })) : Segtree (Max I64);
let lsegtree = LSegtree::build([1, 2, 3].map(|v| Max { v })) : LSegtree (Max I64) (RangeAdd Max I64);
let lsegtree = lsegtree.act_range(0, 2, RangeAdd { a : 10 }); // [11, 12, 3]
assert_eq(|_|"", lsegtree.fold(1, 3).@v, 12);;
assert_eq(|_|"", segtree.fold(0, 2).@v, 2)
```

## Values

### namespace CPLib.Monoid::RangeAssign

#### make

Type: `e -> CPLib.Monoid::RangeAssign m e`

値`c`を代入する作用を作る

##### Parameters

- `c` : 代入する値

### namespace CPLib.Monoid::WeightedSum

#### make_single

Type: `[e : Std::One] e -> CPLib.Monoid::WeightedSum e`

重みが1の値を作る

##### Parameters

- `v` : 要素の値

## Types and aliases

### namespace CPLib.Monoid

#### Max

Defined as: `type Max e = unbox struct { ...fields... }`

最大値のモノイド

単位元は`neg_inf`です。

##### field `v`

Type: `e`

#### Min

Defined as: `type Min e = unbox struct { ...fields... }`

最小値のモノイド

単位元は`inf`です。

##### field `v`

Type: `e`

#### Product

Defined as: `type Product e = unbox struct { ...fields... }`

積のモノイド

##### field `v`

Type: `e`

#### RangeAdd

Defined as: `type [m : *->*] RangeAdd m e = unbox struct { ...fields... }`

区間加算の作用

型引数`m`は作用を受けるモノイドの型コンストラクタ（`Min`、`Max`、`WeightedSum`）、型引数`e`は要素の型です。

##### field `a`

Type: `e`

#### RangeAffine

Defined as: `type [m : *->*] RangeAffine m e = unbox struct { ...fields... }`

アフィン変換`x -> a * x + b`の作用

型引数`m`は作用を受けるモノイドの型コンストラクタ（`Min`、`Max`、`WeightedSum`）、型引数`e`は要素の型です。

`Min` / `Max`に作用させるときは、フィールド`a`を0以上にしてください。負だと作用の定義を満たしません。

##### field `a`

Type: `e`

##### field `b`

Type: `e`

#### RangeAssign

Defined as: `type [m : *->*] RangeAssign m e = unbox struct { ...fields... }`

区間代入の作用

型引数`m`は作用を受けるモノイドの型コンストラクタ（`Min`、`Max`、`WeightedSum`）、型引数`e`は要素の型です。
フィールド`a`が`some(c)`のときは`c`を代入し、`none()`のときは何もしません。`RangeAssign::make(c)`は`RangeAssign { a : some(c) }`を作ります。

##### field `a`

Type: `Std::Option e`

#### RangeMul

Defined as: `type [m : *->*] RangeMul m e = unbox struct { ...fields... }`

区間乗算の作用

型引数`m`は作用を受けるモノイドの型コンストラクタ（`Sum`、`Min`、`Max`、`WeightedSum`）、型引数`e`は要素の型です。

`Min` / `Max`に作用させるときは、フィールド`a`を0以上にしてください。負だと作用の定義を満たしません。

##### field `a`

Type: `e`

#### Sum

Defined as: `type Sum e = unbox struct { ...fields... }`

和のモノイド

`LSegtree`で区間に加算・代入・アフィン変換を作用させる和には`WeightedSum`を使います（区間乗算は`Sum`にも作用します）。

##### field `v`

Type: `e`

#### WeightedSum

Defined as: `type WeightedSum e = unbox struct { ...fields... }`

重みつきの和のモノイド

葉を`make_single`で作ると`w`は1になり、ノードの`w`はそのノードが受け持つ区間の長さになります。
木は`make_single`で作った葉から`build`で作るか、`create`の後に`set`で葉を入れてください。`create`の要素は`w`が0で、作用を受けても変わりません。

##### field `v`

Type: `e`

値と重みの積の和

##### field `w`

Type: `e`

重みの和

## Traits and aliases

## Trait implementations

### impl `[e : Std::LessThan, e : CPLib.Trait::NegInf] CPLib.Monoid::Max e : CPLib.Trait::Monoid`

### impl `[e : Std::LessThan, e : CPLib.Trait::Inf] CPLib.Monoid::Min e : CPLib.Trait::Monoid`

### impl `[e : Std::One, e : Std::Mul] CPLib.Monoid::Product e : CPLib.Trait::Monoid`

### impl `[e : Std::Add] CPLib.Monoid::RangeAdd CPLib.Monoid::Max e : CPLib.Trait::Action`

### impl `[e : Std::Add] CPLib.Monoid::RangeAdd CPLib.Monoid::Min e : CPLib.Trait::Action`

### impl `[e : Std::Add, e : Std::Mul] CPLib.Monoid::RangeAdd CPLib.Monoid::WeightedSum e : CPLib.Trait::Action`

### impl `[m : *->*, e : Std::Zero, e : Std::Add] CPLib.Monoid::RangeAdd m e : CPLib.Trait::Monoid`

### impl `[e : Std::Add, e : Std::Mul] CPLib.Monoid::RangeAffine CPLib.Monoid::Max e : CPLib.Trait::Action`

### impl `[e : Std::Add, e : Std::Mul] CPLib.Monoid::RangeAffine CPLib.Monoid::Min e : CPLib.Trait::Action`

### impl `[e : Std::Add, e : Std::Mul] CPLib.Monoid::RangeAffine CPLib.Monoid::WeightedSum e : CPLib.Trait::Action`

### impl `[m : *->*, e : Std::Zero, e : Std::One, e : Std::Add, e : Std::Mul] CPLib.Monoid::RangeAffine m e : CPLib.Trait::Monoid`

### impl `CPLib.Monoid::RangeAssign CPLib.Monoid::Max e : CPLib.Trait::Action`

### impl `CPLib.Monoid::RangeAssign CPLib.Monoid::Min e : CPLib.Trait::Action`

### impl `[e : Std::Mul] CPLib.Monoid::RangeAssign CPLib.Monoid::WeightedSum e : CPLib.Trait::Action`

### impl `[m : *->*] CPLib.Monoid::RangeAssign m e : CPLib.Trait::Monoid`

### impl `[e : Std::Mul] CPLib.Monoid::RangeMul CPLib.Monoid::Max e : CPLib.Trait::Action`

### impl `[e : Std::Mul] CPLib.Monoid::RangeMul CPLib.Monoid::Min e : CPLib.Trait::Action`

### impl `[e : Std::Mul] CPLib.Monoid::RangeMul CPLib.Monoid::Sum e : CPLib.Trait::Action`

### impl `[e : Std::Mul] CPLib.Monoid::RangeMul CPLib.Monoid::WeightedSum e : CPLib.Trait::Action`

### impl `[m : *->*, e : Std::One, e : Std::Mul] CPLib.Monoid::RangeMul m e : CPLib.Trait::Monoid`

### impl `[e : Std::Zero, e : Std::Add] CPLib.Monoid::Sum e : CPLib.Trait::Monoid`

### impl `[e : Std::Zero, e : Std::Add] CPLib.Monoid::WeightedSum e : CPLib.Trait::Monoid`