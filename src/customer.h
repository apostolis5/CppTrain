#pragma once
#include "bank_account.h"
#include "checking_account.h"
#include "savings_account.h"
#include <vector>
#include <memory>
#include <cstdlib> // For rand()

class Customer
{
public:
    Customer();
    Customer(int checking_balance, int savings_balance);

    BankAccount* get_account(int index) { return accounts[index].get(); }

private:
    std::vector<std::unique_ptr<BankAccount>> accounts;
};