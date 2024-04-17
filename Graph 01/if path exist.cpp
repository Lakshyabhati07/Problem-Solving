#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void dfs(vector<vector<int>> &adjList,vector<int> &vis,int src){

            vis[src]=1;
            for(auto it:adjList[src]){
                if(!vis[it]){
                    dfs(adjList,vis,it);
                }
            }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       
        vector<vector<int>> adjList(n);
        vector<int> vis(n,0);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        dfs(adjList,vis,source);
        if(vis[destination]==0)
        return false;

        return true;
    }
};