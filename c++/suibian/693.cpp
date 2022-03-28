#include<stdio.h>
class Solution {
public:
    bool hasAlternatingBits(int n) {
    int s=(n&1);
    int t;
    n=n>>1;
    while(n)
    {
        t=s^(n&1);
        s=n&1;
        n=n>>1;
        if(t==0)
        return false;
    }
    return true;
    }
};
int main()
{
    Solution t;
    t.hasAlternatingBits(5);
    return 0;
}