#include "do_while.h"

using std::cout; using std::cin;

//Write code for void function prompt_user to loop until
//user opts not to continue.  
void prompt_user()
{
    auto choice = 'n';

    do
    {
        cout<<"Continue to y: ";
        cin>>choice;
        
    } while (choice == 'y' || choice == 'Y');
    
}

void display_menu()
{
    cout<<"\n1-Accounts Receivable\n";
    cout<<"2-Accounts Payable\n";
    cout<<"3-Payroll\n";
    cout<<"4-Exit\n\n";
}

void run_menu()
{
    auto option = 0;

    do
    {
        display_menu();
        cout<<"Enter a menu option: ";
        cin>>option;

        handle_user_option(option);

    } while (option != 4);
    
}

void handle_user_option(int option)
{
    switch(option)   
    {
    case 1:
        cout<<"you selected accounts receivable\n";
        break;
    case 2:
        cout<<"you selected accounts payable\n";
        break;
    case 3:
        cout<<"you selected payroll\n";
        break;
    case 4:
        cout<<"program will exit...\n";
        break;
    default:
        cout<<"Invalid option\n";
        break;
    }
}


