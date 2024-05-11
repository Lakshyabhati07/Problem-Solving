#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
    vector<int> answer(n, -1);
    unordered_map<int, vector<pair<int, int>>> graph;

    for (auto& edge : edges) {
        graph[edge[0]].push_back({edge[1], edge[2]});
        graph[edge[1]].push_back({edge[0], edge[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        pair<int, int> topElement = pq.top();
        int time = topElement.first;
        int node = topElement.second;

        pq.pop();

        if (answer[node] != -1) continue; 

        answer[node] = time;

        for (auto& neighbor : graph[node]) {
            int nextNode = neighbor.first;
            int edgeTime = neighbor.second;

            if (time + edgeTime < disappear[nextNode]) {
                pq.push({time + edgeTime, nextNode});
            }
        }
    }

    return answer;
}
};