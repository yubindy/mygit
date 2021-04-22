#include "all.h"
using namespace std;
int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        try
        {
            if (b == 0)
                throw runtime_error("分母不可为0");
            cout << a / b << endl;
        }
        catch (runtime_error err)
        {   
            cout << err.what();
			cout << "\n是否需要重新输入? Enter y or n:" << endl;
            char s;
            cin>>s;
            if(s=='n')
            break;
        }
    }
}
