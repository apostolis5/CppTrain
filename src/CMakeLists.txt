# Create a library for the core logic so it can be linked by main and tests
add_library(banking_core "bank_account.cpp"
                         "customer.cpp" "transaction.cpp" "savings_account.cpp"
                         "checking_account.cpp" "atm_data.cpp")

# Main executable
add_executable(banking_system "main.cpp")
target_link_libraries(banking_system PRIVATE banking_core)

add_executable(banking_tests "main_test.cpp"
                             "account_test.cpp"
                             "atm_test.cpp"
                             "inheritance_test.cpp"
                             "vector_test.cpp")
target_link_libraries(banking_tests PRIVATE banking_core)

# Register with CTest
add_test(NAME banking_tests COMMAND banking_tests)

# Create a custom target that always runs the tests
add_custom_target(run_tests COMMAND $<TARGET_FILE:banking_tests>)
add_dependencies(run_tests banking_tests)

# Ensure tests are built (and run) when building the main system
add_dependencies(banking_system run_tests)