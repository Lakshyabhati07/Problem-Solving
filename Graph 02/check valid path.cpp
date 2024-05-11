#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    map<int,set<pair<int,int>>> mp;
    
    bool dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int row, int col,int m,int n){
        vis[row][col]=1;
        if(row==n-1 && col == m-1)
        return true;

        for(auto i:mp[grid[row][col]]){

            int newrow=row+i.first;
            int newcol=col+i.second;

            if(newrow>=0 && newcol>=0 && newrow<n && newcol<m && vis[newrow][newcol]==0 && mp[grid[newrow][newcol]].find({-1*i.first,-1*i.second}) != mp[grid[newrow][newcol]].end()){
                if(dfs(grid,vis,newrow,newcol,m,n))
                return true;
            }
        }
    vis[row][col]=false;
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        mp[1]={{0,-1},{0,1}};
        mp[2]={{-1,0},{1,0}};
        mp[3]={{0,-1},{1,0}};
        mp[4]={{0,1},{1,0}};
        mp[5]={{0,-1},{-1,0}};
        mp[6]={{0,1},{-1,0}};

        return dfs(grid,vis,0,0,m,n);
    }
};