class Solution {
public:
    int Solver(int n, vector<int> &dp){
        if(n == 0) return 0;
        if(n < 0) return 1e9+7;
        if(dp[n] != -1) return dp[n];

        int mini = 1e9+7;

        for(int i = 1; i*i <= n; i++){
            mini = min(mini, 1+Solver(n-i*i, dp));
        }
        return dp[n] = mini;
    }
    int numSquares(int n) {
        vector<int> dp(n+1, -1);

        return Solver(n, dp);
    }
};