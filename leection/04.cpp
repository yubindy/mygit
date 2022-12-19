#include "leection.h"
#include <vector>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size()+nums2.size();
        double rul,rul2;
        int i1=0,i2=0;
        int num=0,flag=-1;
        while(i1<nums1.size()&&i2<nums2.size()){
            if(i2==nums2.size()){
                flag=1;
            }
            if(flag==1||nums1[i1]<nums2[i2]){
                rul=rul2;
                rul2=nums1[i1++];
            }else {
                rul=rul2;
                rul2=nums2[i2++];
            }
            num++;
            if(n%2==1&&n/2==num-1){
                return rul2;
            }else if(n%2==0&&n/2+1==num){
                return (rul+rul2)/2;
            }
        }
        return 0;
    }
};
int main(){
    Solution t;
    vector<int> n1{1,2};
    vector<int> n2{3,4};
    t.findMedianSortedArrays(n1,n2);
    return 0;
}