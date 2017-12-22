python-cookbook-in-modern-cpp
=============================

[English](README.md)

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
* [date](https://github.com/HowardHinnant/date)
  - 日付計算のため

## Build

全てをビルドする
```bash
mkdir build
cmake ../src
cd build && make
```

個別にビルドする
```bash
cd src/7/carrying_extra_state_with_callback_functions
mkdir build
cmake ..
cd build && make
```

## Cookbook

| Chapter | Recipe | Description | Code | Docs |
|:-------:|--------|-------------|------|-----|
| 1 | Carrying Extra State with Callback Functions | コールバックをいろいろな形式で書いてみる | [python](src/7/carrying_extra_state_with_callback_functions/example.py) / [C++](src/7/carrying_extra_state_with_callback_functions/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch07.html#_problem_116) |
| 2 | Combining and Concatenating Strings | 文字列をJoinしたりBufferingしたりする | [python](src/2/combining_and_concatenating_strings/example.py) / [C++](src/2/combining_and_concatenating_strings/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch02.html#_solution_34) |
| 3 | Determining Last Friday’s Date | 日付の計算をする | [python](src/3/determining_last_fridays_date/example.py) / [C++](src/3/determining_last_fridays_date/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch03.html#_problem_53) |
| 4 | Creating New Iteration Patterns with Generators | Generatorを使ってrange(0, n, step)っぽい関数を実装する | [python](src/4/creating_new_iteration_patterns_with_generators/example.py) / [C++](src/4/creating_new_iteration_patterns_with_generators/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch04.html#generators) |
| 4 | Iterating Over the Index-Value Pairs of a Sequence | Pythonのenumerateっぽい関数を実装する | [python](src/4/iterate_over_the_index-value_pairs_of_a_list/example.py) / [C++](src/4/iterate_over_the_index-value_pairs_of_a_list/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch04.html#_iterating_over_the_index_value_pairs_of_a_sequence) |
| 4 | Iterating in Reverse | Iteratorと戯れる | [python](src/4/iterating_in_reverse/example.py) / [C++](src/4/iterating_in_reverse/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch04.html#_discussion_60) |
| 4 | Iterating in Sorted Order Over Merged Sorted Iterables | 2つのコレクションを合わせてソートする | [python](src/4/iterating_in_sorted_order_over_merged_sorted_iterables/example.py) / [C++](src/4/iterating_in_sorted_order_over_merged_sorted_iterables/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch04.html#_iterating_in_sorted_order_over_merged_sorted_iterables) |
| 4 | Iterating on Items in Separate Containers | 2つのコレクションをイテレートする | [python](src/4/iterating_on_items_in_separate_containers/example.py) / [C++](src/4/iterating_on_items_in_separate_containers/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch04.html#_iterating_on_items_in_separate_containers) |
| 4 | Delegating Iteration | 自分の子供をイテレートする | [python](src/4/creating_new_iteration_patterns_with_generators/example.py) / [C++](src/4/creating_new_iteration_patterns_with_generators/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch04.html#delegate_iteration) |
| 4 | Defining Generator Functions with Extra State | ステートを持ったenumerateっぽい関数を実装する | [python](src/4/generators_with_state/example.py) / [C++](src/4/generators_with_state/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch04.html#_defining_generator_functions_with_extra_state) |
| 7 | Defining Functions with Default Arguments | デフォルト引数にmutableオブジェクトを渡したときの落とし穴 | [python](src/7/functions_with_default_arguments/example.py) / [C++](src/7/functions_with_default_arguments/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch07.html#_problem_111) |
| 7 | Making an N-Argument Callable Work As a Callable With Fewer Arguments | partial(C++ではbind的な)使うサンプル1  | [python](src/7/making_an_n-argument_callable_work_as_a_callable_with_fewer_arguments/example1.py) / [C++](src/7/making_an_n-argument_callable_work_as_a_callable_with_fewer_arguments/example1.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch07.html#partial) |
| 7 | Making an N-Argument Callable Work As a Callable With Fewer Arguments | partial(C++ではbind的な)使うサンプル2  | [python](src/7/making_an_n-argument_callable_work_as_a_callable_with_fewer_arguments/example2.py) / [C++](src/7/making_an_n-argument_callable_work_as_a_callable_with_fewer_arguments/example2.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch07.html#partial) |
| 7 | Making an N-Argument Callable Work As a Callable With Fewer Arguments | partial(C++ではbind的な)使うサンプル3  | [python](src/7/making_an_n-argument_callable_work_as_a_callable_with_fewer_arguments/example3.py) / [C++](src/7/making_an_n-argument_callable_work_as_a_callable_with_fewer_arguments/example3.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch07.html#partial) |
| 12 | Communicating Between Threads | mutexとlocksを使うサンプル | [python](src/12/how_to_communicate_between_threads/example1.py) / [C++](src/12/how_to_communicate_between_threads/example1.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch12.html#thread_communication) |
| 12 | Communicating Between Threads | condition variableを使うサンプル | [python](src/12/how_to_communicate_between_threads/example2.py) / [C++](src/12/how_to_communicate_between_threads/example2.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch12.html#thread_communication) |

## References

* Online version of Python Cookbook
  - http://chimera.labs.oreilly.com/books/1230000000393/index.html
