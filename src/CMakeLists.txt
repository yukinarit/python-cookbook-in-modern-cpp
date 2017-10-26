cmake_minimum_required(VERSION 3.3)
project(python-cookbook-in-modern-cpp)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../cmake/")
include(fmt)

add_subdirectory(1/calculating_with_dictionaries)
#add_subdirectory(1/determine_the_top_n_items_occurring_in_a_list)
#add_subdirectory(1/filtering_list_elements)
#add_subdirectory(1/finding_out_what_two_dictionaries_have_in_common)
#add_subdirectory(1/finding_the_largest_or_smallest_n_items)
