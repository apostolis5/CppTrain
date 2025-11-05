#include "dynamic_memory.h"

//
using std::cout; using std::shared_ptr;

void use_dynamic_memory_array(const int size)
{
    int* nums = new int[size]{};

    cout<<nums[0]<<"\n";

    delete []nums;
}

int* get_dynamic_memory_array(const int size)
{
    return new int[size];
}

void limit_dynamic_memory_scope(const int num)
{
    int *nums = get_dynamic_memory_array(num);
    cout<<nums[1]<<"\n";

    delete []nums;
}

int* get_dynamic_memory(const int size)
{
    int* nums = new int[size];
    cout<<"Created memory at: "<<nums<<"\n";
    return nums;
}

void delete_dynamic_memory(int* nums)
{
    cout<<"Deleting memory at: "<<nums<<"\n";
    delete []nums;
}

void use_dynamic_memory(const int size)
{
    //create memory
    shared_ptr<int[]> nums(get_dynamic_memory(size), delete_dynamic_memory);
    nums[0] = 5;
    cout<<nums[0]<<"\n";
    
    //we don't have to remember to call delete
    cout<<"Exiting the use dynamic memory function\n";
}