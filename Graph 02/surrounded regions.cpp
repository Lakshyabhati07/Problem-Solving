
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dirR[4]={-1,0,1,0};
    int dirC[4]={0,1,0,-1};
    void dfs(int r,int c,vector<vector<char>>& grid,vector<vector<int>> &vis){
        int n=grid.size();
        int m=grid[0].size();

        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int newRow=r+dirR[i];
            int newCol=c+dirC[i];
            
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 'O' && vis[newRow][newCol] == 0) 
                dfs(newRow, newCol,grid, vis );
        }
    }

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='O')
            dfs(0,j,board,vis);

            if(!vis[n-1][j] && board[n-1][j]=='O')
            dfs(n-1,j,board,vis);
        }

        
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O')
            dfs(i,0,board,vis);

            if(!vis[i][m-1] && board[i][m-1]=='O')
            dfs(i,m-1,board,vis);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                   board[i][j]='X';
                }
            }
        }

    }
};