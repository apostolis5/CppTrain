cmake_minimum_required(VERSION 3.8)

project("BankingSystem")
include_directories(inc)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

include_directories(inc src headers)

# Create a library for the core logic so it can be linked by main and tests
add_library(banking_core "src/bank_account.cpp"
                         )

# Main executable
add_executable(banking_system "src/main.cpp"
                             "testing/account_test.cpp"
                             "testing/atm_test.cpp"
                             "testing/vector_test.cpp")
target_link_libraries(banking_system PRIVATE banking_core)