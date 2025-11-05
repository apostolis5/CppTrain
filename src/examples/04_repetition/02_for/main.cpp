#include"for.h"

using std::cin; using std::cout;

int main() 
{
	display_numbers(5);

	//use sum of squares for
	auto num = 0;

	cout<<"Enter number: ";
	cin>>num;

	auto result = sum_of_squares_for(num);

	cout<<"Result is: "<<result<<"\n";

	return 0;
}