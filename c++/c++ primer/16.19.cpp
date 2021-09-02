#include<algorithm>
#include<vector>
#include<iostream>
#include<list>
//using namespace std;
template <typename T> std::ostream  &show(const T &ftb,std::ostream &os=std::cout)
{
   using size_type=typename T::size_type;
   for(size_type i=0;i!=ftb.size();++i)
   os<<ftb.at(i)<<" ";
   return os;
}
template <typename T> std::ostream  &prin(const T &ftb,std::ostream &os=std::cout)
{
   for(auto i=ftb.begin();i!=ftb.end();i++)
   {
       os<<*i<<" ";
   }
   return os;
}
int main()
{
    std::vector<int> t{1,2,3,4,5,6,7,8};
    std::list<std::string> slis{"c++", "primer", "5th"};
    prin(slis)<<"\n";
    prin(t)<<"\n";
    return 0;
}
