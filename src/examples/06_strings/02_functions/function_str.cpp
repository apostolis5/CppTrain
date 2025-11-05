#include "function_str.h"

using std::string;

void string_value_param(string str)
{
    str = "Python";
}

void string_reference_param(std::string &str)
{
    str = "Python";
}

void string_const_reference_param(const std::string &str)
{
    //str = "Java";can't modify const reference
}