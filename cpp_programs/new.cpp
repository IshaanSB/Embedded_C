#include<iostream>
int x=100;
int main()
{
int x=10;
std::cout<<"x value "<<x<<std::endl;
std::cout<<"x value "<<::x<<std::endl;
return 0;
}
