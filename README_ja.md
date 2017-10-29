python-cookbook-in-modern-cpp
=============================

python-cookbook-in-modern-cppリポジトリへようこそ!
このリポジトリはpython-cookbookのコードをモダンC++で書き直しました。

## Env

macOS Sierra / clang 5.0
CentOS 7.3 / gcc 7.2

## Dependencies

* [range-v3](https://github.com/ericniebler/range-v3)
  - Generatorの代わりとしての遅延評価、各種アルゴリズム等のため
* [fmt](https://github.com/fmtlib/fmt)
  - Pythonっぽいprint文が使いたかったため

## Build

全てをビルドする
```
mkdir build
cmake ../src 
cd build && make
```

個別にビルドする
```
cd src/7/carrying_extra_state_with_callback_functions
mkdir build
cmake ..
cd build && make
```

## Cookbook

| Chapter | Recipe | Description | Code |
|---------|--------|-------------|------|
| 1 | Carrying Extra State with Callback Functions | コールバックをいろいろな形式で書いてみる | [python](src/7/carrying_extra_state_with_callback_functions/example.py) / [C++](src/7/carrying_extra_state_with_callback_functions/example.cpp) |
|         |                                              |                                          |                                                                                                                                     |
|         |                                              |                                          |                                                                                                                                     |

