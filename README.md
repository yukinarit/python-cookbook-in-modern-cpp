python-cookbook-in-modern-cpp
=============================

[日本語](README_ja.md)

Welcome to python-cookbook-in-modern-cpp repo!
This repo is to attempt to write python-cookbook code in modern C++.

## Env

macOS Sierra / clang 5.0
CentOS 7.3 / gcc 7.2

## Dependencies

* [range-v3](https://github.com/ericniebler/range-v3)
  - Lazy evaluation and range algorithims to write python generator like code.
* [fmt](https://github.com/fmtlib/fmt)
  - For python like str.format.
* [date](https://github.com/HowardHinnant/date)
  - For date calculation.

## Build

Build all
```bash
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
| 1 | Carrying Extra State with Callback Functions | Write callback in many ways | [python](src/7/carrying_extra_state_with_callback_functions/example.py) / [C++](src/7/carrying_extra_state_with_callback_functions/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch07.html#_problem_116) |
| 2 | Combining and Concatenating Strings | Join and Buffer string | [python](src/2/combining_and_concatenating_strings/example.py) / [C++](src/2/combining_and_concatenating_strings/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch02.html#_solution_34) |
| 3 | Determining Last Friday’s Date | Date calculation | [python](src/3/determining_last_fridays_date/example.py) / [C++](src/3/determining_last_fridays_date/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch03.html#_problem_53) |
| 7 | Defining Functions with Default Arguments | Pitfall of using mutable type as default argument | [python](src/7/functions_with_default_arguments/example.py) / [C++](src/7/functions_with_default_arguments/example.cpp) | [link](http://chimera.labs.oreilly.com/books/1230000000393/ch07.html#_problem_111) |

## References

* Online version of Python Cookbook
  - http://chimera.labs.oreilly.com/books/1230000000393/ch07.html
