#include<bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
private:
    void dfs(int cx,int cy,int x,int y,vector<vector<char>>&fnt){
        fnt[x][y]='0';
        if(x-1>=0&&fnt[x-1][y]=='1'){
            dfs(cx,cy,x-1,y,fnt);
        }
        if(x+1<cx&&fnt[x+1][y]=='1'){
            dfs(cx,cy,x+1,y,fnt);
        }
        if(y-1>=0&&fnt[x][y-1]=='1'){
            dfs(cx,cy,x,y-1,fnt);
        }
        if(y+1<cy&&fnt[x][y+1]=='1'){
            dfs(cx,cy,x,y+1,fnt);
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        if(!m){return 0;}
        int n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (grid[i][j]=='1'){
                    cnt++;
                    dfs(m,n,i,j,grid);
                }
            }
        }
        return cnt;
    }
};
int main(){
    vector<vector<char>> s{{'1','1','0','1'},{'1','1','0','0'},{'0','0','0','0'}};
    Solution t;
    t.numIslands(s);
}