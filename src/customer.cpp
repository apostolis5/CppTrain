//customer.cpp
#include "customer.h"

using namespace std;

Customer::Customer()
{
    accounts.push_back(make_unique<CheckingAccount>(rand() % 10000 + 1));
    accounts.push_back(make_unique<SavingsAccount>(rand() % 10000 + 1));
}

Customer::Customer(int checking_balance, int savings_balance)
{
   accounts.push_back(make_unique<CheckingAccount>(checking_balance));
   accounts.push_back(make_unique<SavingsAccount>(savings_balance));
}