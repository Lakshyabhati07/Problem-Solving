#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //visited matrix
        int vis[n][m];
        queue<pair<pair<int,int>,int>> q;
        int time=0;
        int countFresh=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},time});
                    vis[i][j]=2;
                }
                else
                vis[i][j]=0;
                
                
                if(grid[i][j]==1){
                    countFresh++;
                }

            }
        }

        //bfs traversal
        int cnt=0;
        int dirCol[]={0,1,0,-1};
        int dirRow[]={-1,0,1,0};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            time=max(t,time);
            q.pop();

            for(int i=0;i<4;i++){
                
                int newRow=row+dirRow[i];
                int newCol=col+dirCol[i];
                
                if(newRow>=0 && newRow<n && newCol>=0 && newCol < m && grid[newRow][newCol]==1 && vis[newRow][newCol]==0){
                    q.push({{newRow,newCol},time+1});
                    vis[newRow][newCol]=2;
                    cnt++;
                }
            }
        }
        if(cnt!=countFresh)
        return -1;

        return time;
    }
};