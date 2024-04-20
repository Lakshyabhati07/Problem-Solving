#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:

vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>> ans(n,vector<int>(m,0));
	    vector<vector<int>> vis(n,vector<int>(m,0));
	    queue<pair<pair<int,int>,int>> q;
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	               
	                q.push({{i,j},0});
	                 vis[i][j]=1;
	                
	            }
	            else{
	                vis[i][j]=0;
	            }
	        }
	    }
	    
	     int dirR[4]={-1,0,+1,0};
         int dirC[4]={0,+1,0,-1};
         
	    while(!q.empty()){
	        int row=q.front().first.first;
            int col=q.front().first.second;
            
            int st=q.front().second;
            
            q.pop();
            
            ans[row][col]=st;
            
            for(int i=0;i<4;i++){
                
                int newRow=row+dirR[i];
                int newCol=col+dirC[i];
                
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && vis[newRow][newCol]==0){
                    vis[newRow][newCol]==1;
                    q.push({{newRow,newCol},st+1});
                }
            }

	        
	    }
	    return ans;
    }
};
