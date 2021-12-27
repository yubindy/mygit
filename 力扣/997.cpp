#include<vector>
#include<stdio.h>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> in(n+1,0);
    vector<int> out(n+1,0);
    for(auto &s:trust)
    {
        in[s[0]]++;
        out[s[1]]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0&&out[i]==n-1)
        return i;
    }
    return -1;
    }
};
int main()
{
    vector<vector<int>> s{{1,2}};
    Solution t;
    printf("%d",t.findJudge(2,s));
    return 0;
}