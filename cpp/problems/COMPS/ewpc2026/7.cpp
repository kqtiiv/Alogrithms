#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

int n, m;

void fastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

ll solveDirection(vector<array<int,3>>& edges) {
    int cnt = edges.size();
    vector<int> idx(cnt);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int x, int y) {
        return edges[x][2] < edges[y][2];
    });

    vector<ll> dist(n + 1, INF);
    dist[1] = 0;

    int i = 0;
    while (i < cnt) {
        int j = i;
        int w = edges[idx[i]][2];
        while (j < cnt && edges[idx[j]][2] == w) j++;

        vector<int> nodes;
        vector<vector<pair<int,int>>> adj;
        unordered_map<int,int> id;
        auto getId = [&](int v) -> int {
            auto it = id.find(v);
            if (it != id.end()) return it->second;
            int nid = nodes.size();
            id[v] = nid;
            nodes.push_back(v);
            adj.push_back({});
            return nid;
        };
        for (int k = i; k < j; k++) {
            int a = edges[idx[k]][0], b = edges[idx[k]][1];
            int la = getId(a), lb = getId(b);
            adj[la].push_back({lb, w});
        }

        int sz = nodes.size();
        vector<ll> local(sz, INF);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
        for (int k = 0; k < sz; k++) {
            local[k] = dist[nodes[k]];
            if (local[k] < INF) pq.push({local[k], k});
        }
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > local[u]) continue;
            for (auto& [v, ww] : adj[u]) {
                if (d + ww < local[v]) {
                    local[v] = d + ww;
                    pq.push({local[v], v});
                }
            }
        }
        for (int k = 0; k < sz; k++) {
            dist[nodes[k]] = min(dist[nodes[k]], local[k]);
        }
        i = j;
    }
    return dist[n];
}

int main() {
    fastIO();

    cin >> n >> m;

    vector<array<int,3>> edges(m);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }

    ll ans = solveDirection(edges);

    if (ans >= INF) cout << "impossible" << endl;
    else cout << ans << endl;

    return 0;
}

