#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> distance(n,vector<int>(n,INT_MAX));
        for(auto it:edges){
            distance[it[0]][it[1]] = it[2];
            distance[it[1]][it[0]] = it[2];
        }

        for(int i=0;i<n;i++)
        distance[i][i]=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(distance[j][i] == INT_MAX || distance[i][k]==INT_MAX)
                    continue;

                    distance[j][k] = min(distance[j][k],distance[j][i]+distance[i][k]);
                }
            }
        }
            int countCity=n;
            int city=-1;

            for(int c=0;c<n;c++){
                int count=0;
                for(int adjc=0;adjc<n;adjc++){
                    if(distance[c][adjc]<=distanceThreshold)
                    count++;

                }
                if(count <= countCity){
                    countCity=count;
                    city=c;
                }
            }
            return city;
    }
};