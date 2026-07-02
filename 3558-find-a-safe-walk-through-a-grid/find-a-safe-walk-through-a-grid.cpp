class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MIN));
        queue<pair<int, pair<int, int>>> q;
        q.push({health - grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        while (!q.empty()) {
            int h = q.front().first, i = q.front().second.first,
                j = q.front().second.second;
            q.pop();
            if (h < dist[i][j])
                continue;
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k], nj = j + dy[k];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    int nh = h - grid[ni][nj];
                    if (nh > dist[ni][nj]) {
                        dist[ni][nj] = nh;
                        q.push({nh, {ni, nj}});
                    }
                }
            }
        }
        return dist[m - 1][n - 1] >= 1;
    }
};