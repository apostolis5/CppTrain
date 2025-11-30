//INHERITANCE from BankAccount base class
#include "bank_account.h"

#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

class CheckingAccount : public BankAccount
{
public:
   //default constructor
   CheckingAccount() { 
      cout << "CheckingAccount Default Constructor called"  << endl;
   }
   
   CheckingAccount(int b) : BankAccount(b){}
};

#endif