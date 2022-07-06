#include <functional>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std; 
class Solution {
public:
    int nextGreaterElement(int n) {
    vector<int> s;
    while (n) {
        s.emplace_back(n%10);
        n/=10;
    }
    int maxs=s[s.size()-1];
    if (max_element(s.begin(),s.end())==(s.end()-1)){
        return -1;
    }
    int j,results;
    sort(s.begin(),s.end());
    for(j=s.size()-1;j>=0;j--){
        if(s[j]==maxs){
        break;
        }
    }
    results=s[j+1];
    for(int i=j+1;i>0;i--){
        results*=10;
        results+=s[j];
    }
    for(int i=j+2;i<s.size();j++){
        results*=10;
        results+=s[j];
    }
    return results;
    }
};
int main(){
    Solution t;
    auto s=t.nextGreaterElement(11);
    auto tt=[&]()->int {printf("result %d ",s);return 0;};
    auto q=tt();
    return 0;
}