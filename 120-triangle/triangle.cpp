class Solution {
public:
    int Solver(int i, int j, int &m, int &n, vector<vector<int>> &triangle, vector<unordered_map<int, int>> &dp){

        if(i >= m || j >= n) return 0;

        if(dp[i].find(j) != dp[i].end()) return dp[i][j];

        int take1 = 1e9+7;
        int take2 = 1e9+7;

        take1 = triangle[i][j] + Solver(i+1, j, m, n, triangle, dp);
        take2 = triangle[i][j] + Solver(i+1, j+1, m, n, triangle, dp);

        return dp[i][j] = min(take1, take2);        
    }
    int minimumTotal(vector<vector<int>>& triangle) {

        int m = triangle.size();
        int n = triangle[m-1].size();

        vector<unordered_map<int, int>> dp(m+1);
        return Solver(0, 0, m, n, triangle, dp);
    }
};