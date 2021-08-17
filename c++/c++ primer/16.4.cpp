#include <iostream>
#include <vector>
#include <list>
template <typename T, typename Y>
T Find(T a, T b, const Y &c)
{
    for (; b != a; a++)
    {
        if (*a == c)
            return a;
    }
    return b;
}
template <typename A>
void print(const A (&arr))
{
    for (const auto ele : arr)
        std::cout << ele << std::endl;
}
template <typename B>
void begin(B) 
int main()
{
    std::vector<int> ivec{1, 2, 3, 4, 5, 6};
    auto iter1 = Find(ivec.begin(), ivec.end(), 3);
    if (iter1 == ivec.end())
        std::cout << "Can not find 3" << std::endl;
    else
        std::cout << "Find 3 at position "
                  << iter1 - ivec.begin() << std::endl;

    std::list<std::string> slis{"c++", "primer", "5th"};
    auto iter2 = Find(slis.begin(), slis.end(), "5th");
    if (iter2 == slis.end())
        std::cout << "Can not find 5th" << std::endl;
    else
        std::cout << "Find \"5th\"" << std::endl;
    int a[6] = {0, 2, 4, 6, 8, 10};
    std::string s[3] = {"c++", "primer", "5th"};
     print(a);
    print(s);
    return 0;
}