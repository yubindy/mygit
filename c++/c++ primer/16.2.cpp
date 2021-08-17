#include<cstring>
#include<functional>
#include<iostream>
template <typename T>
T comper(const T&v1,const T&v2)
{
    if(std::less<T>()(v1,v2)) return 1;
    if(std::less<T>()(v2,v1)) return -1;
}
int main()
{
    std::cout<<comper(1,2)<<std::endl;
}