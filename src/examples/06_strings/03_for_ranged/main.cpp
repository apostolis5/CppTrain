#include<iostream>
#include<string>

using std::cout;
using std::string;

int main()
{
    string lang = "Python";

    for(auto ch: lang)//for(auto& ch: lang) try each loop
    {
        cout<<ch<<"\n";
        ch = 'X';
    }

    for(auto ch: lang)
    {
        cout<<ch<<"\n";
    }


    return 0;
}