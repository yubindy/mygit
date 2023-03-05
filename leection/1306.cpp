#include "leection.h"
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> tp;
        vector<bool> fnt(arr.size(),false);
        int n=arr.size();
        tp.push(start);
        while(!tp.empty()){
            int p=tp.front();
            tp.pop();
            if(arr[p]==0){
                return true;
            }else{
                printf("index %d val %d\n",p,arr[p]);
            }
            fnt[p]=true;
            if(p+arr[p]<n&&!fnt[p+arr[p]]){
                printf("l index %d val %d\n",p+arr[p],arr[p+arr[p]]);
                tp.push(p+arr[p]);
            }
            if(p-arr[p]>=0&&!fnt[p-arr[p]]){
                printf("r index %d val %d\n",p-arr[p],arr[p-arr[p]]);
                tp.push(p-arr[p]);
            }
        }
        return false;
    }
};
int main(){

}