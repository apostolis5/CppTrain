#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int result = Catch::Session().run(argc, argv);
    if (result != 0) {
        cout << "Tests failed!" << endl;
        return result;
    }

    cout << " ***************************Banking System Initialized*************************** " << endl;
    
    return 0;
}