python-cookbook-in-modern-cpp
=============================

[日本語](README_ja.md)

Welcome to python-cookbook-in-modern-cpp repo!
This repo is to attempt to write python-cookbook code in modern C++.

## Env

macOS Sierra / clang 6.0
CentOS 7.3 / gcc 7.2

## Dependencies

* [range-v3](https://github.com/ericniebler/range-v3)
  - Lazy evaluation and range algorithims to write python generator like code.
* [fmt](https://github.com/fmtlib/fmt)
  - For python like str.format.
* [date](https://github.com/HowardHinnant/date)
  - For date calculation.
* [libzmq](https://github.com/zeromq/libzmq)
  - For networking.
* [zmqpp](https://github.com/zeromq/zmqpp)
  - For networking.

## Build

Build all
```bash
git clone --recursive https://github.com/yukinarit/python-cookbook-in-modern-cpp.git
cd python-cookbook-in-modern-cpp
mkdir build
cmake ../src
cd build && make
```

Build a project
```bash
cd src/7/carrying_extra_state_with_callback_functions
mkdir build
cmake ..
cd build && make
```

## Cookbook

| Chapter | Recipe | Description | Code | Docs |
|:-------:|--------|-------------|------|-----|
| 1 | Determining the Most Frequently Occurring Items in a Sequence | Find an item that has the most occurence in list | [python](src/7/determine_the_top_n_items_occurring_in_a_list/example.py) / [C++](src/7/determine_the_top_n_items_occurring_in_a_list/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch07.html#_problem_116) |
| 1 | Calculating with Dictionaries | Calculating max/min of item in dictionary | [python](src/1/calculating_with_dictionaries/example.py) / [C++](src/1/calculating_with_dictionaries/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch01.html#dictcalc) |
| 1 | Filtering Sequence Elements | Appliying various filterings to list | [python](src/1/filtering_list_elements/example.py) / [C++](src/1/filtering_list_elements/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch01.html#_filtering_sequence_elements) |
| 1 | Finding Commonalities in Two Dictionaries | Calculating intersect from two dictionary | [python](src/1/finding_out_what_two_dictionaries_have_in_common/example.py) / [C++](src/1/finding_out_what_two_dictionaries_have_in_common/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch01.html#_finding_commonalities_in_two_dictionaries) |
| 1 | Finding the Largest or Smallest N Items | Finding the Largest or Smallest N Items from list | [python](src/1/finding_the_largest_or_smallest_n_items/example.py) / [C++](src/1/finding_the_largest_or_smallest_n_items/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch01.html#findingthelargestorsmallest) |
| 1 | Implementing a Priority Queue | Implementing a Priority Queue | [python](src/1/implementing_a_priority_queue/example.py) / [C++](src/1/implementing_a_priority_queue/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch01.html#priorityqueue) |
| 1 | Keeping the Last N Items | Search a word in a text file and get the last n lines before the mached line | [python](src/1/keeping_the_last_n_items/example.py) / [C++](src/1/keeping_the_last_n_items/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch01.html#_keeping_the_last_n_items) |
| 1 | Mapping Keys to Multiple Values in a Dictionary | Dict manipulation | [python](src/1/mapping_names_to_sequence_elements/example1.py) / [C++](src/1/mapping_names_to_sequence_elements/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch01.html#multidict) |
| 1 | Removing Duplicates from a Sequence while Maintaining Order | Removing duplicates using range algorithm (Generator in Python) | [python](src/1/removing_duplicates_from_a_sequence_while_maintaining_order/example.py) / [C++](src/1/removing_duplicates_from_a_sequence_while_maintaining_order/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch01.html#_removing_duplicates_from_a_sequence_while_maintaining_order) |
| 1 | Removing Duplicates from a Sequence while Maintaining Order | WIP | [python](src/1/removing_duplicates_from_a_sequence_while_maintaining_order/example2.py) / [C++]() | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch01.html#_removing_duplicates_from_a_sequence_while_maintaining_order) |
| 1 | Sorting a List of Dictionaries by a Common Key | Sorting dict by key (Using rambda in C++, itemgetter in python) | [python](src/1/sort_a_list_of_dictionaries_by_a_common_key/example.py) / [C++](src/1/sort_a_list_of_dictionaries_by_a_common_key/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch01.html#itemgetter) |
| 1 | Sorting Objects Without Native Comparison Support | Sorting Objects Without specifiying a comparison function | [python](src/1/sort_objects_without_native_comparison_support/example.py) / [C++](src/1/sort_objects_without_native_comparison_support/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch01.html#_sorting_objects_without_native_comparison_support) |
| 2 | Combining and Concatenating Strings | Join and Buffer string | [python](src/2/combining_and_concatenating_strings/example.py) / [C++](src/2/combining_and_concatenating_strings/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch02.html#_solution_34) |
| 3 | Determining Last Friday’s Date | Date calculation | [python](src/3/determining_last_fridays_date/example.py) / [C++](src/3/determining_last_fridays_date/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch03.html#_problem_53) |
| 4 | Creating New Iteration Patterns with Generators | Implement range(0, n, step) like function with generator | [python](src/4/creating_new_iteration_patterns_with_generators/example.py) / [C++](src/4/creating_new_iteration_patterns_with_generators/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch04.html#generators) |
| 4 | Iterating Over the Index-Value Pairs of a Sequence | Implement python's enumerate function | [python](src/4/iterate_over_the_index-value_pairs_of_a_list/example.py) / [C++](src/4/iterate_over_the_index-value_pairs_of_a_list/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch04.html#_iterating_over_the_index_value_pairs_of_a_sequence) |
| 4 | Iterating in Reverse | How to work with iterator | [python](src/4/iterating_in_reverse/example.py) / [C++](src/4/iterating_in_reverse/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch04.html#_discussion_60) |
| 4 | Iterating in Sorted Order Over Merged Sorted Iterables | Merge and sort two collections | [python](src/4/iterating_in_sorted_order_over_merged_sorted_iterables/example.py) / [C++](src/4/iterating_in_sorted_order_over_merged_sorted_iterables/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch04.html#_iterating_in_sorted_order_over_merged_sorted_iterables) |
| 4 | Iterating on Items in Separate Containers | Iterate two collections | [python](src/4/iterating_on_items_in_separate_containers/example.py) / [C++](src/4/iterating_on_items_in_separate_containers/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch04.html#_iterating_on_items_in_separate_containers) |
| 4 | Delegating Iteration | Iterate childlen | [python](src/4/creating_new_iteration_patterns_with_generators/example.py) / [C++](src/4/creating_new_iteration_patterns_with_generators/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch04.html#delegate_iteration) |
| 4 | Defining Generator Functions with Extra State | Implement enumerate like function with state | [python](src/4/generators_with_state/example.py) / [C++](src/4/generators_with_state/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch04.html#_defining_generator_functions_with_extra_state) |
| 7 | Carrying Extra State with Callback Functions | Write callback in many ways | [python](src/7/carrying_extra_state_with_callback_functions/example.py) / [C++](src/7/carrying_extra_state_with_callback_functions/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch07.html#_problem_116) |
| 7 | Writing Functions That Accept Any Number of Arguments | Writing a function that accepts variable number arguments using Variadic template | [python](src/7/functions_that_accept_any_number_of_arguments/example.py) / [C++](src/7/functions_that_accept_any_number_of_arguments/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch07.html#_writing_functions_that_accept_any_number_of_arguments) |
| 7 | Defining Functions with Default Arguments | Pitfall of using mutable type as default argument | [python](src/7/functions_with_default_arguments/example.py) / [C++](src/7/functions_with_default_arguments/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch07.html#_problem_111) |
| 7 | Making an N-Argument Callable Work As a Callable With Fewer Arguments | An example1 using partial(bind in C++) | [python](src/7/making_an_n-argument_callable_work_as_a_callable_with_fewer_arguments/example1.py) / [C++](src/7/making_an_n-argument_callable_work_as_a_callable_with_fewer_arguments/example1.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch07.html#partial) |
| 7 | Making an N-Argument Callable Work As a Callable With Fewer Arguments | An example2 using partial(bind in C++) | [python](src/7/making_an_n-argument_callable_work_as_a_callable_with_fewer_arguments/example2.py) / [C++](src/7/making_an_n-argument_callable_work_as_a_callable_with_fewer_arguments/example2.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch07.html#partial) |
| 7 | Making an N-Argument Callable Work As a Callable With Fewer Arguments | An example3 using partial(bind in C++) | [python](src/7/making_an_n-argument_callable_work_as_a_callable_with_fewer_arguments/example3.py) / [C++](src/7/making_an_n-argument_callable_work_as_a_callable_with_fewer_arguments/example3.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch07.html#partial) |
| 11 | Creating a TCP server | Creating a TCP echo client | [python](src/11/creating_a_tcp_server/echoclient.py) / [C++](src/11/creating_a_tcp_server/echoclient.cpp) |
| 11 | Creating a TCP server | Creating a TCP echo server | [python](src/11/creating_a_tcp_server/echoserv.py) / [C++](src/11/creating_a_tcp_server/echoserv.cpp) |
| 11 | Creating a TCP server | Creating a TCP echo server using iostream like interface | [python](src/11/creating_a_tcp_server/echoserv2.py) / [C++](src/11/creating_a_tcp_server/echoserv2.cpp) |
| 9 | Applying Decorators to Class and Static Methods | Trying to make decorator-ish macro using variadic template | [python](src/9/applying_decorators_to_class_and_static_methods/example.py) / [C++](src/9/applying_decorators_to_class_and_static_methods/example.cpp) |
| 12 | Communicating Between Threads | An example using mutex and locks | [python](src/12/how_to_communicate_between_threads/example1.py) / [C++](src/12/how_to_communicate_between_threads/example1.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch12.html#thread_communication) |
| 12 | Communicating Between Threads | An example using condition variable | [python](src/12/how_to_communicate_between_threads/example2.py) / [C++](src/12/how_to_communicate_between_threads/example2.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch12.html#thread_communication) |
| 12 | How to create thread pool | Creating simple thread pool using lock and condition variable | [python](src/12/how_to_create_a_thread_pool/example1.py) / [C++](src/12/how_to_create_a_thread_pool/example1.cpp) |  |

## References

* Online version of Python Cookbook
  - http://chimera.labs.oreilly.com/books/1230000000393/index.html
