#include<vector>
#include<iostream>

using std::cout;
using std::vector;

int main()
{
    vector<int> nums{6, 3, 10, 25, 7};

    for(auto n: nums)//for(auto &n: nums)& allows changing of values
    {
        cout<<n<<"\n";
        n = 0;
    }

    for(auto n: nums)
    {
        cout<<n<<"\n";
    }

    return 0;
}