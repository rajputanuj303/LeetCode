class Solution {
public:

    int m, n;
    vector<vector<vector<int>>> dp;
    bool Solver(int i, int j, int countPar, vector<vector<char>> &grid){

        countPar += (grid[i][j] == '(') ? 1 : -1;

        if(countPar < 0) return false;

        if(dp[i][j][countPar] != -1) return dp[i][j][countPar];

        if(i == m-1 && j == n-1){
            return dp[i][j][countPar] = (countPar == 0);            
        }

        bool validPath = false;

        if(i+1 < m) validPath |= Solver(i+1, j, countPar, grid);
        if(j+1 < n) validPath |= Solver(i, j+1, countPar, grid);

        return dp[i][j][countPar] = validPath;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if(grid[0][0] == ')' || grid[m-1][n-1] == '(' || (m+n-1)%2 != 0) return false;

        dp.assign(m+1, vector<vector<int>>(n+1, vector<int>(m+n+1, -1)));

        return Solver(0, 0, 0, grid);
    }
};