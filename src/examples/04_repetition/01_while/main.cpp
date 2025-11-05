#include "while.h"

using std::string;
using std::cin; using std::cout;

int main() 
{
	string txt = "Hello";
	
	display(txt);

	//use sum of squares function
	auto num = 0;
	cout<<"Enter a number: ";
	cin>>num;

	auto result = sum_of_squares(num);
	cout<<"Result: "<<result<<"\n";
	
	return 0;
}