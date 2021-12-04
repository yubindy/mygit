#include <iostream>
#include<string>
#include<map>
#include<memory>
template <typename T>
class objectpool
{
public:
  std::shared_ptr<T> get(const std::string &key);
private:
  
};
class stock
{
private:
    std::map<std::string,std::string> s;
public:
     std::string show(std::string &t)
    {
        return s[t];
    }
};
int main()
{
}
