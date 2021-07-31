#include <iostream>
#include <string>
#include <vector>
#include <exception>
using namespace std;
//异常处理
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		try
		{
			if (b == 0)
				throw runtime_error("被除数不能为0\n");
			cout << a / b << endl;
		}
		catch(runtime_error err)
		{
                cout<<err.what()<<"\n是否重新输入(y or n)\n";
				char t;
				cin>>t;
				if(t=='n')
				break;
		}
	}
}