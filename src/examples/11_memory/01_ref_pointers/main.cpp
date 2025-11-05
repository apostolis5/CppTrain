#include "ref_pointers.h"
#include<iostream>

using std::cout;

int main() 
{
	/*int num = 5;
	int& num_ref = num;

	cout<<"Value of num via num_ref: "<<num_ref<<"\n";
	cout<<"num value: "<<num<<"\n";
	num_ref = 20;
	cout<<"Value of num via num_ref: "<<num_ref<<"\n";
	cout<<"num value: "<<num<<"\n";
	
	num_ref = num1;
	cout<<"Value of num via num_ref: "<<num_ref<<"\n";
	cout<<"value of num1: "<<num1<<"\n";

	num_ref = 100;
	cout<<"Value of num via num_ref: "<<num_ref<<"\n";
	cout<<"num value: "<<num<<"\n";
	cout<<"value of num1: "<<num1<<"\n";*/

	int num3 = 50;
	int* num_ptr = &num3;
	
	cout<<"Memory address num_ptr points to: "<<num_ptr<<"\n";
	cout<<"Memory where num_ptr is stored: "<<&num_ptr;
	cout<<"Value of num3 via num_ptr: "<<*num_ptr<<"\n";
	cout<<"Num3 value: "<<num3<<"\n";
	
	*num_ptr = 200;
	cout<<"Value of num3 via num_ptr: "<<*num_ptr<<"\n";
	cout<<"Num3 value: "<<num3<<"\n";

	int num4 = 100;
	num_ptr = &num4;
	cout<<"Memory address num_ptr points to: "<<num_ptr<<"\n";
	cout<<"Value of num4 via num_ptr: "<<*num_ptr<<"\n";
	cout<<"Num4 value: "<<num4<<"\n";

	*num_ptr = 1000;
	cout<<"Value of num4 via num_ptr: "<<*num_ptr<<"\n";
	cout<<"Num4 value: "<<num4<<"\n";

	return 0;
}