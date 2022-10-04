#include <bits/stdc++.h>
#include <ratio>
using namespace std;
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if(matrix.size()==0){
        return false;
    }
    int n=0;
    int m=matrix[0].size()-1;
    while(n>=0&&m>=0&&n<matrix.size()&&m<matrix[0].size()){
        if(matrix[n][m]>target){
            m--;
        }else if(matrix[n][m]<target){
            n++;
        }else if((matrix[n][m]==target)){
            return true;
        }
    }
    return false;
    }
};
int main(){
    return 0;
}