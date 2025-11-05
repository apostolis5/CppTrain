add_executable(ex_08_tests "08_classes_tests.cpp")
target_include_directories(ex_08_tests PRIVATE /home/ubuntu/Desktop/course-artgonzalezacc-master/src/08_classes/01_bank)
target_link_libraries(ex_08_tests ex_08_01_library)
add_test(NAME ex_08_tests COMMAND ex_08_tests -s)