class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Optimization: If k is large enough to walk straight along the perimeter,
        // the shortest path is simply the Manhattan distance.
        if (k >= m + n - 2) {
            return m + n - 2;
        }
        
        // visited[r][c] stores the maximum remaining k seen when visiting (r, c)
        vector<vector<int>> visited(m, vector<int>(n, -1));
        
        // Queue stores: {row, col, remaining_k, steps}
        queue<vector<int>> q;
        q.push({0, 0, k, 0});
        visited[0][0] = k;
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            int r = curr[0], c = curr[1], remK = curr[2], steps = curr[3];
            
            // First time reaching the destination is guaranteed to be the shortest
            if (r == m - 1 && c == n - 1) {
                return steps;
            }
            
            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                if (nr >= 0 && nc >= 0 && nr < m && nc < n) {
                    int nextK = remK - grid[nr][nc];
                    
                    // Only proceed if we have enough eliminations left AND 
                    // we arrive at (nr, nc) with strictly more eliminations than any prior (shorter/equal) path
                    if (nextK >= 0 && nextK > visited[nr][nc]) {
                        visited[nr][nc] = nextK;
                        q.push({nr, nc, nextK, steps + 1});
                    }
                }
            }
        }
        
        return -1;
    }
};