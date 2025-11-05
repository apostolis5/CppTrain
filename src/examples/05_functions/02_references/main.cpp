#include<iostream>

using std::cout; 

int main()
{
    auto num = 5;
    cout<<"Memory address of num: "<<&num<<"\n";
    int &num_ref = num;//save the address of num into num_ref

    cout<<"Value of num: "<<num<<"\n";
    cout<<"Value of num via num_ref "<<num_ref<<"\n";
    num_ref = 10;
    cout<<"Value of num: "<<num<<"\n";
    cout<<"Value of num via num_ref "<<num_ref<<"\n";

    cout<<&num_ref<<"\n";

    return 0;
}