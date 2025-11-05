//atm.h
#include<iostream>
#include<memory>
#include<vector>
#include "bank_account.h"
#include "customer.h"

void display_menu();
void run_menu(std::vector<Customer>& customers);
void handle_option(BankAccount* account, int option);
int scan_card(int max_value);
