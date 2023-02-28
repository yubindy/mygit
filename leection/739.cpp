#include "leection.h"
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> fnk;
        int num=0;
        vector<int> p(temperatures.size(),0);
       for(int i=0;i<temperatures.size();i++){
           if(fnk.empty()){
               fnk.push(temperatures[i]);
           }
           num=0;
           while(temperatures[i]>=fnk.top()&&!fnk.empty()){
               temperatures[i-fnk.size()]=++num;
               fnk.pop();
           }
           fnk.push(temperatures[i]);
       }
        return p;
    }
};
int main(){

}