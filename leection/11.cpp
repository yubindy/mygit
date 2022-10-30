#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=height.size()-1;
        int j=0;
        int rul=min(height[i],height[j])*(i-j);
        printf("%d",rul);
        while(j<i){
            if(height[i]>height[j]){
                j++;
            }else{
                i--;
            }
            rul=max(rul,min(height[i],height[j])*(i-j));
        }
        return rul;
    }
};