cmake_minimum_required(VERSION 3.8)

project("BankingSystem")
include_directories(inc)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

include_directories(inc src headers)

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