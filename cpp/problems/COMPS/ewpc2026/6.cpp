#include <bits/stdc++.h>
using namespace std;

void fastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int n, m;
vector<vector<pair<int,int>>> adj;
vector<int> edgeCycleId;
int numCycles = 0;

vector<int> disc, parVert, parEdge;
int timer_ = 0;

void dfsIterative(int root) {
    vector<int> stackV, stackIt;
    stackV.push_back(root);
    stackIt.push_back(0);
    disc[root] = ++timer_;
    parVert[root] = -1; parEdge[root] = -1;
    while (!stackV.empty()) {
        int u = stackV.back();
        int &it = stackIt.back();
        if (it < (int)adj[u].size()) {
            auto [v, eid] = adj[u][it];
            it++;
            if (eid == parEdge[u]) continue;
            if (!disc[v]) {
                disc[v] = ++timer_;
                parVert[v] = u; parEdge[v] = eid;
                stackV.push_back(v);
                stackIt.push_back(0);
            } else if (disc[v] < disc[u]) {
                int cid = numCycles++;
                edgeCycleId[eid] = cid;
                int cur = u;
                while (cur != v) {
                    edgeCycleId[parEdge[cur]] = cid;
                    cur = parVert[cur];
                }
            }
        } else {
            stackV.pop_back();
            stackIt.pop_back();
        }
    }
}

int numBlocks;
vector<vector<int>> auxAdj;

int findSeparator(int a, int b) {
    int N = n + numBlocks;
    vector<int> par(N, -2);
    vector<int> qv; qv.reserve(N);
    qv.push_back(a); par[a] = -1;
    for (size_t qi = 0; qi < qv.size(); qi++) {
        int u = qv[qi];
        if (u == b) break;
        for (int w : auxAdj[u]) if (par[w] == -2) { par[w] = u; qv.push_back(w); }
    }
    int p1 = par[b];
    if (p1 == -1) return -1;
    int p2 = par[p1];
    if (p2 == a) return -1;
    return p2;
}

int nextStep(int from, int to) {
    if (from == to) return from;
    vector<int> dist(n, -1);
    queue<int> q;
    dist[to] = 0; q.push(to);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto [v, eid] : adj[u]) if (dist[v] == -1) { dist[v] = dist[u] + 1; q.push(v); }
    }
    for (auto [v, eid] : adj[from]) if (dist[v] == dist[from] - 1) return v;
    return from;
}

int main() {
    fastIO();

    cin >> n >> m;

    vector<int> eu(m), ev(m);
    adj.assign(n, {});
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        eu[i] = x; ev[i] = y;
        adj[x].push_back({y, i});
        adj[y].push_back({x, i});
    }

    disc.assign(n, 0);
    parVert.assign(n, -1);
    parEdge.assign(n, -1);
    edgeCycleId.assign(m, -1);
    for (int i = 0; i < n; i++) if (!disc[i]) dfsIterative(i);

    vector<int> blockOfEdge(m, -1);
    int nextBlock = numCycles;
    for (int e = 0; e < m; e++)
        blockOfEdge[e] = (edgeCycleId[e] != -1) ? edgeCycleId[e] : nextBlock++;
    numBlocks = nextBlock;

    vector<set<int>> blockVertSet(numBlocks);
    for (int e = 0; e < m; e++) {
        blockVertSet[blockOfEdge[e]].insert(eu[e]);
        blockVertSet[blockOfEdge[e]].insert(ev[e]);
    }

    auxAdj.assign(n + numBlocks, {});
    for (int b = 0; b < numBlocks; b++)
        for (int v : blockVertSet[b]) {
            auxAdj[v].push_back(n + b);
            auxAdj[n + b].push_back(v);
        }

    int sof, ter, but;
    cin >> sof >> ter >> but;
    sof--; ter--; but--;

    int pos[2] = {sof, ter}; // pos[0] = sof, pos[1] = ter

    bool fixed = false;
    int fixedIdx = -1;    // 0 = sof , 1 = ter
    bool endgame = false;
    int stillIdx = -1;    // which one stays put

    const int MAXMOVES = 4 * (n + m) + 1000;
    for (int turn = 0; turn < MAXMOVES; turn++) {
        int refIdx = fixed ? (1 - fixedIdx) : 0;
        int g = findSeparator(pos[refIdx], but);

        if (g == -1) {
            if (!endgame) {
                endgame = true;
                stillIdx = fixed ? fixedIdx : 0;
                fixed = false; fixedIdx = -1;
            }
            int moveIdx = 1 - stillIdx;
            pos[moveIdx] = nextStep(pos[moveIdx], but);
        } else {
            endgame = false; stillIdx = -1;
            if (!fixed) {
                pos[0] = nextStep(pos[0], g);
                pos[1] = nextStep(pos[1], g);
                if (pos[0] == g) { fixed = true; fixedIdx = 0; }
                else if (pos[1] == g) { fixed = true; fixedIdx = 1; }
            } else {
                int moveIdx = 1 - fixedIdx;
                pos[moveIdx] = nextStep(pos[moveIdx], g);
                if (pos[moveIdx] == g) fixedIdx = moveIdx;
            }
        }

        cout << (pos[0] + 1) << " " << (pos[1] + 1) << endl;

        string resp;
        if (!(cin >> resp)) break;
        if (resp == "Caught!") break;
        but = stoi(resp) - 1;
    }

    return 0;
}