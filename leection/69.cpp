#include "leection.h"
class Solution {
public:
    int mySqrt(int x) {
        if(x<=1){
            return x;
        }
        long long left=0,right=x;
        long long mid=(left+right)/2;
        while(left<right){
            mid=(left+right)/2;
            if(mid*mid<x&&(mid+1)*(mid+1)>x||mid*mid==x){
                return mid;
            }else if(mid*mid<x){
                left=mid;
            }else{
                right=mid;
            }
        }
        return mid;
    }
};
int main() {
}