#include "my_vector.h"
#include<string>
//
using std::cout; 


int main()
{   
    Vector<int> nums(3);
    nums.PushBack(65);
    cout<<nums[0]<<"\n";

    nums.PushBack(16);
    cout<<nums[1]<<"\n";

    Vector<double> nums1(3);
    nums1.PushBack(5.5);
    cout<<nums1[0]<<"\n";

    Vector<float> floats(3);
    floats.PushBack(6.6);
    cout<<floats[0]<<"\n";


    return 0;
}

