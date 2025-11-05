//write code for for stack_array and display each element to screen
#include "arrays_mem.h"

using std::cout; using std::string;

//function prototype for stack_array
void use_stack_array()
{
    const auto SIZE = 3;
    int numbers[SIZE]{5, 7, 8};

    for(int i=0; i < SIZE; i++)
    {
        cout<<numbers[i]<<"\n";
    }
}

void array_months()
{
    const auto SIZE = 3;
    int month_numbers[SIZE] {1,2,3};
    string month_names[SIZE]{"Jan", "Feb", "Mar"};

    for(int i=0; i < SIZE; i++)
    {
        cout<<month_numbers[i]<<" "<<month_names[i]<<"\n";
    }
}

void arrays_and_pointers()
{
    const auto SIZE = 3;
    int numbers[SIZE]{1,2,3};

    cout<<numbers<<"\n";
    cout<<*numbers<<"\n";

    int* ptr = numbers;

    cout<<ptr<<" "<<*ptr<<"\n";

    *ptr++;//jump 4 bytes forward

    cout<<ptr<<" "<<*ptr<<"\n";

    *ptr++;//jump 4 bytes forward

    cout<<ptr<<" "<<*ptr<<"\n";

    *ptr--;//jump 4 bytes back

    cout<<ptr<<" "<<*ptr<<"\n";

    *ptr--;//jump 4 bytes back

    cout<<ptr<<" "<<*ptr<<"\n";
}

void display_array(int* nums)
{
    //sentinel value
    for(auto i=0; nums[i] != -1; i++)
    {
        cout<<nums[i]<<"\n";
    }

    cout<<"\n";
}

void display_array(int* nums, const int SIZE)
{
    for(auto i=0; i < SIZE; i++)
    {
        cout<<nums[i]<<"\n";
    }
}