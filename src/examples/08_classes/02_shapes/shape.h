//shape.h
#include<iostream>

class Shape //abstract class-cannot be used directly as a variable/create instance 
{
public:    
    virtual void draw() = 0; //pure virtual function
};