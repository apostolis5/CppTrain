cmake_minimum_required(VERSION 3.8)

project("BankingSystem")
include_directories(inc)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

MACRO(HEADER_DIRECTORIES return_list)
    FILE(GLOB_RECURSE new_list *.h)
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()

HEADER_DIRECTORIES(header_list)

include_directories(${header_list})

# Create a library for the core logic so it can be linked by main and tests
add_library(banking_core "src/bank_account.cpp"
                         )

# Main executable
add_executable(banking_system "src/main.cpp")
target_link_libraries(banking_system PRIVATE banking_core)

add_executable(banking_tests "testing/main_test.cpp"
                             "testing/account_test.cpp"
                             "testing/atm_test.cpp"
                             "testing/vector_test.cpp")
target_link_libraries(banking_tests PRIVATE banking_core)

# Register with CTest
add_test(NAME banking_tests COMMAND banking_tests)

# Create a custom target that always runs the tests
add_custom_target(run_tests COMMAND $<TARGET_FILE:banking_tests>)
add_dependencies(run_tests banking_tests)

# Ensure tests are built (and run) when building the main system
add_dependencies(banking_system run_tests)