#include <iostream>
#include <string.h>
using namespace std;
class Employee
{
public:
       Employee() {cout<<"自定义函数"<<nums<<endl;id=nums++;};
       Employee(string wer) : name(wer),id(nums++) { cout<<"构造函数"<<(nums-1)<<endl;}
       Employee(const Employee &e) : name(e.name), id(nums++) {cout<<"where"<<id<<endl;}
       Employee &operator=(const Employee &vec) { cout<<"赋值"<<nums<<endl;name=vec.name; return *this;}
       void read() { cout<<"姓名: "<<this->name<<" 证号:"<<this->id<<endl;}
private:
       string name;
       int id;
       static int nums;
};
int Employee::nums=0;
int main()
{
    Employee a("陈"),b=a,c;
    c=b;
    a.read();
    b.read();
    c.read();
}