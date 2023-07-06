cmake_minimum_required(VERSION 3.0.2)
project(ctci)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)

add_library(${PROJECT_NAME}
    # Arrays and strings
    src/arrays_and_strings/is_unique.cpp
    src/arrays_and_strings/check_permutation.cpp
    src/arrays_and_strings/urlify.cpp
    src/arrays_and_strings/palindrome_permutation.cpp
    src/arrays_and_strings/one_away.cpp
    src/arrays_and_strings/string_compression.cpp
    src/arrays_and_strings/rotate_matrix.cpp
    src/arrays_and_strings/zero_matrix.cpp
    src/arrays_and_strings/string_rotation.cpp

    # Linked lists
    src/linked_lists/remove_dups.cpp
    src/linked_lists/return_kth_to_last.cpp
    src/linked_lists/delete_middle_node.cpp
    src/linked_lists/partition.cpp
    src/linked_lists/sum_lists.cpp
    src/linked_lists/palindrome.cpp
    src/linked_lists/intersection.cpp
    src/linked_lists/loop_detection.cpp

    # Stacks and Queues
    src/stacks_and_queues/set_of_stacks.cpp
    src/stacks_and_queues/my_queue.cpp
    src/stacks_and_queues/sort.cpp
    src/stacks_and_queues/animal_shelter.cpp

    # Trees and Graphs
    src/trees_and_graphs/route_between_nodes.cpp
)

include_directories(
    include
    ${GTEST_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_test
    test/test_main.cpp
    test/test_utils.cpp
    test/test_arrays_and_strings.cpp
    test/test_linked_lists.cpp
    test/test_stacks_and_queues.cpp
    test/test_trees_and_graphs.cpp
)

target_link_libraries(${PROJECT_NAME}_test
    ${PROJECT_NAME}
    ${GTEST_LIBRARIES}
    pthread
)