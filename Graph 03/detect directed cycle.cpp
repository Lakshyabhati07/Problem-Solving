#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<int> adj[], int start, vector<int>& vis, vector<int>& pathVis) {
        vis[start] = 1;
        pathVis[start] = 1;
        
        for (int it : adj[start]) {
            if (!vis[it]) {
                if (dfs(adj, it, vis, pathVis)) {
                    return true;
                }
            } else if (pathVis[it]) {
                return true;
            }
        }
        
        pathVis[start] = 0;
        return false;
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(adj, i, vis, pathVis)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
