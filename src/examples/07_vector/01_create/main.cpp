#include<vector>
#include<iostream>

using std::cout;
using std::vector;

int main()
{
    vector<int> nums0;
    nums0.push_back(5);//add one element to the vector

    vector<int> nums1{1, 10, 7};

    cout<<nums1[0]<<"\n";

    vector<int> nums3(5, 100);

    for(auto n: nums3)
    {
        cout<<n<<"\n";
    }

    cout<<"\n";

    vector<char> chars{'a', 'b'};

    for(auto ch: chars)
    {
        cout<<ch;
    }

    cout<<"\n";

    for(auto i=0; i < chars.size(); i++)
    {
        cout<<chars[i]<<"\n";
    }


    return 0;
}