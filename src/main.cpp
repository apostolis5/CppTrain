#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include <string>
#include <optional>
#include "bank_internal_system.h" 
#include "atm.h"                  
using namespace std;

int main(int argc, char* argv[]) {
    // Run Catch2 tests
    int result = Catch::Session().run(argc, argv);
    if (result != 0) {
        cout << "Tests failed!\n";
        return result;
    }

    cout << "\n***************************Banking System Initialized*************************** \n";
    
return 0;
}
