#include "val_ref.h"

void value_param(int num)
{
    num = 20;
}

void reference_param(int &num)
{
    num = 20;
}

void const_reference_param(const int &num)
{
    //num = 20; can't modify a read only const reference parameter
}