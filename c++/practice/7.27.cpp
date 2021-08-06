#include "7.27.h"
#include<iostream>
using namespace std;
int main()
{
    green myScreen();
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << "\n";
    myScreen.display(cout);
    std::cout << "\n";

    return 0;
}