#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
void printVec(vector<int>& vec)
{
#ifndef NDEBUG
	cout << "vector size: " << vec.size() << endl;
#endif
	if (!vec.empty()) 
	{
		auto tmp = vec.back();
		vec.pop_back();
		printVec(vec);
		cout << tmp << " ";
	}
} 
int main(int argc, char** argv)
{
	vector<int> vec;
	for(int i=0;i<10;i++)
	{
		vec.push_back(i);
	}
	printVec(vec);
	cout << endl;
	return 0;
}