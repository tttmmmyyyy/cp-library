# CPLib.Monoid

Defined in cp-library@0.15.0

セグメント木でよく使うモノイドと作用を提供するモジュール。

値のモノイドは`Sum`、`Product`、`Min`、`Max`、`WeightedSum`、作用は`RangeAdd`、`RangeAssign`、`RangeAffine`です。
値はフィールド`v`に入れ、`Max { v }`で作り`x.@v`で読みます。

作用の型は、作用を受けるモノイドの型コンストラクタを最初の型引数に取ります。たとえば`Max I64`への区間加算は`RangeAdd Max I64`です。
用意している組み合わせは次の通りです。

| 作用 | `Min` / `Max` | `WeightedSum` |
| --- | --- | --- |
| `RangeAdd` | 値に足す | 和に「足す値 * 重みの和」を足す |
| `RangeAssign` | 値を置き換える | 和を「代入する値 * 重みの和」にする |
| `RangeAffine` | なし | 和を「`a` * 和 + `b` * 重みの和」にする |

自分の型と名前がぶつかるときは、`Monoid::Max`のように名前空間を付けて書きます。

ここにないモノイドと作用は、型を作成して`CPLib.Trait`の`Monoid`と`Action`を実装すれば使えます。
書き方は`CPLib.Segtree`と`CPLib.LSegtree`のモジュールの説明の例にあります。

```fix
import CPLib.LSegtree;
import CPLib.Monoid;
// 区間への加算と、区間の最大値の取得ができるセグメント木
let tree = build([1, 2, 3].map(|v| Monoid::Max { v })) : LSegtree (Monoid::Max I64) (RangeAdd Monoid::Max I64);
let tree = tree.act_range(0, 2, RangeAdd { v : 10 }); // [11, 12, 3]
let (_, res) = tree.fold(1, 3);
assert_eq(|_|"", res.@v, 12)
```

## Values

### namespace CPLib.Monoid::RangeAssign

#### make

Type: `a -> CPLib.Monoid::RangeAssign f a`

値`v`を代入する作用を作る

##### Parameters

- `v` : 代入する値

### namespace CPLib.Monoid::WeightedSum

#### make

Type: `[a : Std::One] a -> CPLib.Monoid::WeightedSum a`

重みが1の葉を作る

##### Parameters

- `v` : 要素の値

## Types and aliases

### namespace CPLib.Monoid

#### Max

Defined as: `type Max a = unbox struct { ...fields... }`

最大値のモノイド

単位元は`neg_inf`です。

##### field `v`

Type: `a`

#### Min

Defined as: `type Min a = unbox struct { ...fields... }`

最小値のモノイド

単位元は`inf`です。

##### field `v`

Type: `a`

#### Product

Defined as: `type Product a = unbox struct { ...fields... }`

積のモノイド

##### field `v`

Type: `a`

#### RangeAdd

Defined as: `type [f : *->*] RangeAdd f a = unbox struct { ...fields... }`

区間加算の作用

`f`は作用を受けるモノイドの型コンストラクタ（`Min`、`Max`、`WeightedSum`）、`a`は要素の型です。

区間加算は`Min`の`inf`と`Max`の`neg_inf`にも足します。
`init`で作った要素の値はこれらなので、区間加算をする要素には先に`set`か`build`で値を入れてください。

##### field `v`

Type: `a`

#### RangeAffine

Defined as: `type [f : *->*] RangeAffine f a = unbox struct { ...fields... }`

アフィン変換`x -> a * x + b`の作用

`f`は作用を受けるモノイドの型コンストラクタ（`WeightedSum`）、`a`は要素の型です。

##### field `a`

Type: `a`

##### field `b`

Type: `a`

#### RangeAssign

Defined as: `type [f : *->*] RangeAssign f a = unbox struct { ...fields... }`

区間代入の作用

`f`は作用を受けるモノイドの型コンストラクタ（`Min`、`Max`、`WeightedSum`）、`a`は要素の型です。
`v`が`none()`のときは何もしません。

##### field `v`

Type: `Std::Option a`

#### Sum

Defined as: `type Sum a = unbox struct { ...fields... }`

和のモノイド

区間に作用させる和には`WeightedSum`を使います。

##### field `v`

Type: `a`

#### WeightedSum

Defined as: `type WeightedSum a = unbox struct { ...fields... }`

重みつきの和のモノイド

区間に作用させる`RangeAdd`、`RangeAssign`、`RangeAffine`は、和の変化を求めるのに重みの和を使います。
葉を`make`で作ると重みは1になり、`weight`は区間の要素数になります。
木は`make`で作った葉から`build`で作るか、`init`の後に`set`で葉を入れてください。`init`の要素は重みが0で、作用を受けても変わりません。

重みに1以外を使うこともできます。要素`i`の葉を`WeightedSum { v : d * w, weight : w }`（`d`は`i`桁目の数字、`w`は`10^(n-1-i)`）にすれば、`v`は数字の列を10進数として読んだ値になります。

##### field `v`

Type: `a`

値と重みの積の和

##### field `weight`

Type: `a`

重みの和

## Traits and aliases

## Trait implementations

### impl `[a : Std::LessThan, a : CPLib.Trait::NegInf] CPLib.Monoid::Max a : CPLib.Trait::Monoid`

### impl `[a : Std::LessThan, a : CPLib.Trait::Inf] CPLib.Monoid::Min a : CPLib.Trait::Monoid`

### impl `[a : Std::One, a : Std::Mul] CPLib.Monoid::Product a : CPLib.Trait::Monoid`

### impl `[a : Std::Add] CPLib.Monoid::RangeAdd CPLib.Monoid::Max a : CPLib.Trait::Action`

### impl `[a : Std::Add] CPLib.Monoid::RangeAdd CPLib.Monoid::Min a : CPLib.Trait::Action`

### impl `[a : Std::Add, a : Std::Mul] CPLib.Monoid::RangeAdd CPLib.Monoid::WeightedSum a : CPLib.Trait::Action`

### impl `[f : *->*, a : Std::Zero, a : Std::Add] CPLib.Monoid::RangeAdd f a : CPLib.Trait::Monoid`

### impl `[a : Std::Add, a : Std::Mul] CPLib.Monoid::RangeAffine CPLib.Monoid::WeightedSum a : CPLib.Trait::Action`

### impl `[f : *->*, a : Std::Zero, a : Std::One, a : Std::Add, a : Std::Mul] CPLib.Monoid::RangeAffine f a : CPLib.Trait::Monoid`

### impl `CPLib.Monoid::RangeAssign CPLib.Monoid::Max a : CPLib.Trait::Action`

### impl `CPLib.Monoid::RangeAssign CPLib.Monoid::Min a : CPLib.Trait::Action`

### impl `[a : Std::Mul] CPLib.Monoid::RangeAssign CPLib.Monoid::WeightedSum a : CPLib.Trait::Action`

### impl `[f : *->*] CPLib.Monoid::RangeAssign f a : CPLib.Trait::Monoid`

### impl `[a : Std::Zero, a : Std::Add] CPLib.Monoid::Sum a : CPLib.Trait::Monoid`

### impl `[a : Std::Zero, a : Std::Add] CPLib.Monoid::WeightedSum a : CPLib.Trait::Monoid`