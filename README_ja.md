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
| 1 | Determining the Most Frequently Occurring Items in a Sequence | リストから歳頻出の要素を探し出す | [python](src/1/determine_the_top_n_items_occurring_in_a_list/example.py) / [C++](src/1/determine_the_top_n_items_occurring_in_a_list/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch01.html#_determining_the_most_frequently_occurring_items_in_a_sequence) |
| 1 | Calculating with Dictionaries | dictから値がmax/minの要素を探し出す | [python](src/1/calculating_with_dictionaries/example.py) / [C++](src/1/calculating_with_dictionaries/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch01.html#dictcalc) |
| 1 | Filtering Sequence Elements | リストにいろいろなフィルタリングをかける | [python](src/1/filtering_list_elements/example.py) / [C++](src/1/filtering_list_elements/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch01.html#_filtering_sequence_elements) |
| 1 | Finding Commonalities in Two Dictionaries | 二つのdictから共通部分を取る | [python](src/1/finding_out_what_two_dictionaries_have_in_common/example.py) / [C++](src/1/finding_out_what_two_dictionaries_have_in_common/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch01.html#_finding_commonalities_in_two_dictionaries) |
| 1 | Finding the Largest or Smallest N Items | リストから最大/最小ベストNを見つける | [python](src/1/finding_the_largest_or_smallest_n_items/example.py) / [C++](src/1/finding_the_largest_or_smallest_n_items/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch01.html#findingthelargestorsmallest) |
| 1 | Implementing a Priority Queue | Priority Queueを実装する | [python](src/1/implementing_a_priority_queue/example.py) / [C++](src/1/implementing_a_priority_queue/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch01.html#priorityqueue) |
| 1 | Keeping the Last N Items | ファイルから単語検索し、マッチした行の直前の行を返す | [python](src/1/keeping_the_last_n_items/example.py) / [C++](src/1/keeping_the_last_n_items/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch01.html#_keeping_the_last_n_items) |
| 1 | Mapping Keys to Multiple Values in a Dictionary | dict操作 | [python](src/1/mapping_names_to_sequence_elements/example1.py) / [C++](src/1/mapping_names_to_sequence_elements/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch01.html#multidict) |
| 1 | Removing Duplicates from a Sequence while Maintaining Order | Rangeアルゴリズム(Pythonではgenerator)を使ってdictから重複を消す1 | [python](src/1/removing_duplicates_from_a_sequence_while_maintaining_order/example.py) / [C++](src/1/removing_duplicates_from_a_sequence_while_maintaining_order/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch01.html#_removing_duplicates_from_a_sequence_while_maintaining_order) |
| 1 | Removing Duplicates from a Sequence while Maintaining Order | WIP | [python](src/1/removing_duplicates_from_a_sequence_while_maintaining_order/example2.py) / WIP | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch01.html#_removing_duplicates_from_a_sequence_while_maintaining_order) |
| 1 | Sorting a List of Dictionaries by a Common Key | キーでdictをソートする (C++はラムダ, Pythonではitemgetterを使って) | [python](src/1/sort_a_list_of_dictionaries_by_a_common_key/example.py) / [C++](src/1/sort_a_list_of_dictionaries_by_a_common_key/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch01.html#itemgetter) |
| 1 | Transforming and Reducing Data at the Same Time | WIP | [python](src/1/transforming_and_reducing_data_at_the_same_time/example.py) / WIP | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch01.html#generatorargs) |
| 1 | Sorting Objects Without Native Comparison Support | 比較関数を与えずにソートする | [python](src/1/sort_objects_without_native_comparison_support/example.py) / [C++](src/1/sort_objects_without_native_comparison_support/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch01.html#_sorting_objects_without_native_comparison_support) |
| 2 | Combining and Concatenating Strings | 文字列をJoinしたりBufferingしたりする | [python](src/2/combining_and_concatenating_strings/example.py) / [C++](src/2/combining_and_concatenating_strings/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch02.html#_solution_34) |
| 3 | Determining Last Friday’s Date | 日付の計算をする | [python](src/3/determining_last_fridays_date/example.py) / [C++](src/3/determining_last_fridays_date/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch03.html#_problem_53) |
| 4 | Creating New Iteration Patterns with Generators | Generatorを使ってrange(0, n, step)っぽい関数を実装する | [python](src/4/creating_new_iteration_patterns_with_generators/example.py) / [C++](src/4/creating_new_iteration_patterns_with_generators/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch04.html#generators) |
| 4 | Iterating Over the Index-Value Pairs of a Sequence | Pythonのenumerateっぽい関数を実装する | [python](src/4/iterate_over_the_index-value_pairs_of_a_list/example.py) / [C++](src/4/iterate_over_the_index-value_pairs_of_a_list/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch04.html#_iterating_over_the_index_value_pairs_of_a_sequence) |
| 4 | Iterating in Reverse | Iteratorと戯れる | [python](src/4/iterating_in_reverse/example.py) / [C++](src/4/iterating_in_reverse/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch04.html#_discussion_60) |
| 4 | Iterating in Sorted Order Over Merged Sorted Iterables | 2つのコレクションを合わせてソートする | [python](src/4/iterating_in_sorted_order_over_merged_sorted_iterables/example.py) / [C++](src/4/iterating_in_sorted_order_over_merged_sorted_iterables/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch04.html#_iterating_in_sorted_order_over_merged_sorted_iterables) |
| 4 | Iterating on Items in Separate Containers | 2つのコレクションをイテレートする | [python](src/4/iterating_on_items_in_separate_containers/example.py) / [C++](src/4/iterating_on_items_in_separate_containers/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch04.html#_iterating_on_items_in_separate_containers) |
| 4 | Delegating Iteration | 自分の子供をイテレートする | [python](src/4/creating_new_iteration_patterns_with_generators/example.py) / [C++](src/4/creating_new_iteration_patterns_with_generators/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch04.html#delegate_iteration) |
| 4 | Defining Generator Functions with Extra State | ステートを持ったenumerateっぽい関数を実装する | [python](src/4/generators_with_state/example.py) / [C++](src/4/generators_with_state/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch04.html#_defining_generator_functions_with_extra_state) |
| 7 | Carrying Extra State with Callback Functions | コールバックをいろいろな形式で書いてみる | [python](src/7/carrying_extra_state_with_callback_functions/example.py) / [C++](src/7/carrying_extra_state_with_callback_functions/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch07.html#_problem_116) |
| 7 | Writing Functions That Accept Any Number of Arguments | Variadic templateを使って可変長引数をとる関数を作る | [python](src/7/functions_that_accept_any_number_of_arguments/example.py) / [C++](src/7/functions_that_accept_any_number_of_arguments/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch07.html#_writing_functions_that_accept_any_number_of_arguments) |
| 7 | Defining Functions with Default Arguments | デフォルト引数にmutableオブジェクトを渡したときの落とし穴 | [python](src/7/functions_with_default_arguments/example.py) / [C++](src/7/functions_with_default_arguments/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch07.html#_problem_111) |
| 7 | Making an N-Argument Callable Work As a Callable With Fewer Arguments | partial(C++ではbind的な)使うサンプル1  | [python](src/7/making_an_n-argument_callable_work_as_a_callable_with_fewer_arguments/example1.py) / [C++](src/7/making_an_n-argument_callable_work_as_a_callable_with_fewer_arguments/example1.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch07.html#partial) |
| 7 | Making an N-Argument Callable Work As a Callable With Fewer Arguments | partial(C++ではbind的な)使うサンプル2  | [python](src/7/making_an_n-argument_callable_work_as_a_callable_with_fewer_arguments/example2.py) / [C++](src/7/making_an_n-argument_callable_work_as_a_callable_with_fewer_arguments/example2.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch07.html#partial) |
| 7 | Making an N-Argument Callable Work As a Callable With Fewer Arguments | partial(C++ではbind的な)使うサンプル3  | [python](src/7/making_an_n-argument_callable_work_as_a_callable_with_fewer_arguments/example3.py) / [C++](src/7/making_an_n-argument_callable_work_as_a_callable_with_fewer_arguments/example3.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch07.html#partial) |
| 11 | Creating a TCP server | TCPのechoクライアントを作る | [python](src/11/creating_a_tcp_server/echoclient.py) / [C++](src/12/creating_a_tcp_server/echoclient.cpp) |  |
| 11 | Creating a TCP server | TCPのechoサーバーを作る | [python](src/11/creating_a_tcp_server/echoserv.py) / [C++](src/12/creating_a_tcp_server/echoserv.cpp) |  |
| 11 | Creating a TCP server | iostreamっぽいのインターフェースを使ってTCPのechoサーバーを作る | [python](src/11/creating_a_tcp_server/echoserv2.py) / [C++](src/12/creating_a_tcp_server/echoserv2.cpp) |  |
| 12 | Communicating Between Threads | mutexとlocksを使うサンプル | [python](src/12/how_to_communicate_between_threads/example1.py) / [C++](src/12/how_to_communicate_between_threads/example1.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch12.html#thread_communication) |
| 12 | Communicating Between Threads | condition variableを使うサンプル | [python](src/12/how_to_communicate_between_threads/example2.py) / [C++](src/12/how_to_communicate_between_threads/example2.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch12.html#thread_communication) |

## References

* Online version of Python Cookbook
  - http://chimera.labs.oreilly.com/books/1230000000393/index.html
