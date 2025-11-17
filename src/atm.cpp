//atm.cpp
#include "atm.h"
using std::cin; using std::cout; using std::unique_ptr;



void ATM::display_balance()
{
    cout<<"Current Account of ATM has balance --> "<< account->get_balance() <<"\n";
}