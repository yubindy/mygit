#include "leection.h"
class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1=num1.size()-1;
        int n2=num2.size()-1;
        int add=0;
        string str;
        while(n1>=0||n2>=0||add!=0){
            int x1=n1>=0?num1[n1]-'0':0;
            int x2=n2>=0?num2[n2]-'0':0;
            int num=x1+x2+add;
            add=num/10;
            num=num%10;
            printf("%d+%d=%d\n",x1,x2,num);
            str.push_back(num+'0');
            n1--;
            n2--;
        }
        reverse(str.begin(),str.end());
        return str;
        }
};
int main(){
    
}