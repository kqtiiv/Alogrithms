#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> healthGrid(m, vector<int>(n, -1));
        healthGrid[0][0] = health-grid[0][0];

        priority_queue<tuple<int, int, int>> pq;
        pq.push({healthGrid[0][0], 0, 0});
        
        int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};

        while (!pq.empty()) {
            auto [h, x, y] = pq.top(); pq.pop();
            if (h < healthGrid[x][y]) continue;
            if (x == m-1 && y == n-1) return h >= 1;

            for (int d=0; d<4; d++) {
                int nx = x+dx[d], ny = y+dy[d];
                if (nx>=0 && ny>=0 && nx<m && ny<n) {
                    int newHealth = h - grid[nx][ny];
                    if (newHealth > healthGrid[nx][ny]) {
                        pq.push({newHealth, nx, ny});
                        healthGrid[nx][ny] = newHealth;
                    }
                }
            }
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol = Solution();
    vector<vector<int>> grid = {{1,1,1,1}};
    cout << sol.findSafeWalk(grid, 4) << endl;
    return 0;
}

