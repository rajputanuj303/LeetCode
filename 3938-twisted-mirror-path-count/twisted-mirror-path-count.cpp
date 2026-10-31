class Solution {
public:
    int MOD = 1e9+7;
    
    int Solver(int i, int j, int &m, int &n, int dir, 
               vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
        if(i == m-1 && j == n-1) return 1;
        if(i >= m || j >= n) return 0;
        
        if(dp[i][j][dir] != -1) return dp[i][j][dir];
        
        long long count = 0;
        
        if(grid[i][j] == 0) {
            // free cell → can go both directions
            count = (Solver(i+1, j, m, n, 0, grid, dp) % MOD +
                     Solver(i, j+1, m, n, 1, grid, dp) % MOD) % MOD;
        }
        else if(grid[i][j] == 1) {
            // special cell → move only based on dir
            if(dir == 0) {
                // if we came down, now go right
                count = Solver(i, j+1, m, n, 1, grid, dp) % MOD;
            } else {
                // if we came right, now go down
                count = Solver(i+1, j, m, n, 0, grid, dp) % MOD;
            }
        }
        
        return dp[i][j][dir] = count;
    }
    
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // 3D dp: dp[m][n][2]
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, -1)));
        
        return Solver(0, 0, m, n, 0, grid, dp);
    }
};
