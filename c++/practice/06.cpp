#ifndef TEST_PERSON_H
#define TEST_PERSON_H
#include<iostream>
#include<cctype>
#include<string.h>
#include<vector>
using namespace std;
class Person {
private:
    string strName;         // 姓名
    string strAddress;      // 地址
public:
    Person() = default;
    Person(const string &name, const string &addr) {
        strName = name;
        strAddress = addr;
    }
    explicit Person(std::istream &is) { read(is, *this); }
    
    string getName() const { return strName; }          // 返回姓名
    string getAddress() const { return strAddress; }    // 返回地址
    std::istream &read(std::istream &is, Person &per);
    std::ostream &print(std::ostream &os, const Person &per);
};

std::istream & Person::read(std::istream &is, Person &per) {
    is >> per.strName >> per.strAddress;
    return is;
}

std::ostream & Person::print(std::ostream &os, const Person &per) {
    os << per.getName() << per.getAddress();
    return os;
}

#endif //TEST_PERSON_H