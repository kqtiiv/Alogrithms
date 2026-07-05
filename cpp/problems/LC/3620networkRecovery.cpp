#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = edges.size();
        vector<vector<pair<int, int>>> adj(n);

        for (auto& e: edges) {
            int u = e[0], v= e[1], cost = e[2];
            if (online[u]&&online[v]) adj[u].push_back({v, cost});
        }

        vector<int> minCost(n, INT_MAX);

        priority_queue<pair<int, int>> pq;
        pq.push({0, 0});

        

        while (!pq.empty()) {
            auto [cost, node] = pq.top(); pq.pop();
            if (node == n-1) return minCost[n-1];
            for (auto [v, c]: adj[node]) {
                pq.push({cost+c, v});
                minCost[v] = min(minCost[node], c);
            }
        }

        return -1;
    }
};