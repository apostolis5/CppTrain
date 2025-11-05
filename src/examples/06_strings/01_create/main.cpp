#include<iostream>
#include<string>

using std::cout;
using std::string;

int main()
{
    string s0("Initial string");
    cout<<s0<<"\n";

    string s1(s0);
    cout<<s1<<"\n";

    string s2(s0, 8, 3);
    cout<<s2<<"\n";

    string s3("Another character sequence", 12);
    cout<<s3<<"\n";

    string s4(10, 'x');
    cout<<s4<<"\n";

    string s5(10, 65);
    cout<<s5<<"\n";

    string s6("123456abac**(**)");
    cout<<s6<<"\n";

    cout<<s0 + s1<<"\n";

    return 0;
}