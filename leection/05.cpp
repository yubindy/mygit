#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    pair<int,int> hui(const string&s,int left,int right){
        printf("debug  %d %d\n",right,left);
        while(left>0&&right<s.size()){
            if(s[left]==s[right]){
                right++;
                left--;
            }else{
                return make_pair(left+1,right-1);
            }
        }
        if(s[left]==s[right]){
        printf("debug  %d %d\n",right,left);
        return make_pair(left,right);
        }
        return make_pair(left+1,right-1);
    }
    string longestPalindrome(string s) {
        int beg=0,end=0;
        for(int i=1;i<s.size();i++){
            auto a=hui(s,i,i);
            if(a.second-a.first>end-beg){
                beg=a.first;
                end=a.second;
                printf("1 i=%d %d %d\n",i,beg,end);
            }
            auto b=hui(s,i,i+1);
            printf("debug i=%d %d %d\n",i,b.second,b.first);
            if(b.second-b.first>end-beg){
                beg=b.first;
                end=b.second;
                printf("2 i=%d %d %d\n",i,beg,end);
            }
        }
        return s.substr(beg,end-beg+1);
    }
};
int main() {
    Solution p;
    string s("bb");
    printf("%s", p.longestPalindrome(s).data());
    return 0;
}