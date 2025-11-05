#include "static.h"

using std::cout;

void use_non_static()
{
    int num = 0;
    num++;
    cout<<num<<"\n";
}

void use_static()
{
    static int num = 0;
    num++;
    cout<<num<<"\n";
}