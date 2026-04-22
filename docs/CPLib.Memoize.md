# CPLib.Memoize

Defined in cp-library@0.12.1

関数のメモ化（memoize）

基本的な使い方：
```
// フィボナッチ数列 mod 2^64 を計算するMemoizeモナド
//
// `m`はメモ化につかうメモリの型。`HashMap`や`Array`を呼び出し時に選択。
//
// 結果をメモしたいので、値を計算するモナドを `memoize(n)`に渡す
fib : [m : Memory, Key m = I64, Value m = U64] I64 -> Memoize m U64 = |n| memoize(n) $ (
    if n <= 1 { pure $ n.u64 };
    pure $ *fib(n - 1) + *fib(n - 2)
);

// フィボナッチ数列の和 mod 2^64 を計算するMemoizeモナド
//
// 内部で呼ばれるfibはメモ化されるべきだが、sum_fibの結果自体はメモしないので、`memoize`しない。
sum_fib : [m : Memory, Key m = I64, Value m = U64] I64 -> Memoize m U64 = |n| (
    range(0, n).fold_m(0.u64, |n, sum| pure $ sum + *fib(n))
);

test_hashmap : IO () = (
    let m = sum_fib(1e5); // 答えを計算するモナドを作成
    let x = m.run_with_hashmap(1e5); // キャパシティ（計算中に超えるとrehashが発生）
    assert_eq(|_|"test_hashmap", x, 14406452726835625052_U64);;
    pure()
);

test_array : IO () = (
    let m = sum_fib(1e5); // 答えを計算するモナドを作成
    let x = m.run_with_array(1e5); // サイズ（計算中に超えるとout of range）
    assert_eq(|_|"test_array", x, 14406452726835625052_U64);;
    pure()
);
```

## Values

### namespace CPLib.Memoize

#### memoize

Type: `[m : CPLib.Memoize::Memory, CPLib.Memoize::Memory::Key m = k, CPLib.Memoize::Memory::Value m = v] k -> CPLib.Memoize::Memoize m v -> CPLib.Memoize::Memoize m v`

モナドアクションをメモ化する

`memoize(x) $ f` は、
- キー`x`に対する値がメモリに存在する場合はそれを返す。
- 存在しない場合はモナド`f`を実行し、結果をメモリに保存してから返す。

##### Parameters

- `x` : メモ化のキー
- `f` : キー`x`に対する値を計算するモナド

#### run_with_array

Type: `Std::I64 -> CPLib.Memoize::Memoize (Std::Array (Std::Option v)) a -> a`

配列上でメモ化モナドを実行する

##### Parameters

- `size` : 配列のサイズ。計算中に超えた場合はout of rangeでプログラム終了。
- `f` : メモ化モナド

#### run_with_hashmap

Type: `Std::I64 -> CPLib.Memoize::Memoize (HashMap::HashMap k v) a -> a`

ハッシュマップ上でメモ化モナドを実行する

##### Parameters

- `capacity` : ハッシュマップの初期容量。計算中に超えた場合はrehashが発生。
- `f` : メモ化モナド

#### run_with_memory

Type: `m -> CPLib.Memoize::Memoize m a -> a`

メモ化モナドをメモリ`m`上で実行する

##### Parameters

- `m` : メモ化に使うメモリ領域
- `f` : メモ化モナド

### namespace CPLib.Memoize::Memory

#### find

Type: `[m : CPLib.Memoize::Memory] CPLib.Memoize::Memory::Key m -> m -> Std::Option (CPLib.Memoize::Memory::Value m)`

Trait member of `CPLib.Memoize::Memory`

#### insert

Type: `[m : CPLib.Memoize::Memory] CPLib.Memoize::Memory::Key m -> CPLib.Memoize::Memory::Value m -> m -> m`

Trait member of `CPLib.Memoize::Memory`

## Types and aliases

### namespace CPLib.Memoize

#### Memoize

Defined as: `type Memoize m a = unbox struct { ...fields... }`

メモ化モナド

`m`はメモ化に使うメモリの型（`HashMap`や`Array`など）。

## Traits and aliases

### namespace CPLib.Memoize

#### trait `m : Memory`

##### type `Key`

Defined as: `Key m`

##### type `Value`

Defined as: `Value m`

##### method `insert`

Type: `CPLib.Memoize::Memory::Key m -> CPLib.Memoize::Memory::Value m -> m -> m`

##### method `find`

Type: `CPLib.Memoize::Memory::Key m -> m -> Std::Option (CPLib.Memoize::Memory::Value m)`

## Trait implementations

### impl `CPLib.Memoize::Memoize m : Std::Monad`

### impl `[k : Hash::HashKey] HashMap::HashMap k v : CPLib.Memoize::Memory`

### impl `Std::Array (Std::Option v) : CPLib.Memoize::Memory`