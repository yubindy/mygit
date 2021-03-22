
#include <iostream>
#include<vector>
#include <string>
using namespace std;
int main()
{	
	string s("cdsiao dcsdcs?!!!");
	//int num = s.size();
	for (char i=0 ; i<s.size() ; i++)
	{
		if(!ispunct(s[i]))
        cout<<s[i];
	}
}