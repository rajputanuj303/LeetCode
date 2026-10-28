class Solution {
public:
    int m, n;
    vector<vector<vector<bool>>> dp;
    
    void Solver(int i, int j, int XOR, vector<vector<int>> &grid){

        XOR ^= grid[i][j];

        if(dp[i][j][XOR]) return;
        dp[i][j][XOR] = true;

        if(i+1 < m) Solver(i+1, j, XOR, grid);
        if(j+1 < n) Solver(i, j+1, XOR, grid);
        
    }
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.resize(m, vector<vector<bool>>(n, vector<bool>(1024, false)));
        
        Solver(0, 0, 0, grid);

        for(int i = 0; i<1024; i++){
            if(dp[m-1][n-1][i]) return i;
        }
        
        return -1;
    }
};