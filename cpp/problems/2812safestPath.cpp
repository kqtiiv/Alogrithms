#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        if (grid[0][0]) return 0;
        int n = grid.size();
        vector<vector<int>> safeness(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]) {
                    safeness[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int d=0; d<4; d++) {
                int nx = x+dx[d], ny = y+dy[d];
                if (nx>=0&&ny>=0&&nx<n&&ny<n&&safeness[nx][ny]==-1) {
                    q.push({nx, ny});
                    safeness[nx][ny] = safeness[x][y] + 1;
                }
            }
        }

        vector<vector<int>> maxSafe(n, vector<int>(n, -1));
        priority_queue<tuple<int, int, int>> pq;
        pq.push({safeness[0][0], 0, 0});
        maxSafe[0][0] = safeness[0][0];

        while(!pq.empty()) {
            auto [s, r, c] = pq.top(); pq.pop();
            if (s < maxSafe[r][c]) continue;
            if (r==n-1 && c==n-1) return s;
            for (int d=0; d<4; d++) {
                int nr=r+dx[d], nc=c+dy[d];
                if (nr>=0&&nr<n&&nc>=0&&nc<n) {
                    int newSafe = min(s, safeness[nr][nc]);
                    if (newSafe > maxSafe[nr][nc]) {
                        maxSafe[nr][nc] = newSafe;
                        pq.push({newSafe, nr, nc});
                    }
                }
            }
        }

        return maxSafe[n-1][n-1];
    }
};