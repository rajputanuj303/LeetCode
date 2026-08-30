class Solution {
public:
    bool Solver(int n, bool AliceTurn, vector<vector<int>> &dp) {
        if (n == 0) return false;
        if(dp[n][AliceTurn] != -1) return dp[n][AliceTurn]; 

        for (int i = 1; i * i <= n; i++) {
            if (!Solver(n - i * i, !AliceTurn, dp)) return dp[n][AliceTurn] = true;
        }

        return dp[n][AliceTurn] = false;
    }

    bool winnerSquareGame(int n) {
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return Solver(n, true, dp);
    }
};