class Solution {
public:

    int Solver(int i, int prev, string &s, vector<vector<int>> &dp){
        if(i >= s.size()) return 0;

        if(dp[i][prev] != -1) return dp[i][prev];

        int take0 = INT_MAX;
        int take1 = INT_MAX;

        if(prev == 0){
            if(s[i] == '0'){
                take0 = (dp[i+1][0] != -1) ? dp[i+1][0] : Solver(i+1, 0, s, dp);
                take1 = (dp[i+1][1] != -1) ? (1 + dp[i+1][1]) : (1 + Solver(i+1, 1, s, dp));
            }else{
                take0 = (dp[i+1][0] != -1) ? (1 + dp[i+1][0]) : (1 + Solver(i+1, 0, s, dp));
                take1 = (dp[i+1][1] != -1) ? dp[i+1][1] : Solver(i+1, 1, s, dp);
            }
        }else{
            if(s[i] == '0'){
                take1 = (dp[i+1][1] != -1) ? (1 + dp[i+1][1]) : (1 + Solver(i+1, 1, s, dp));
            }else{
                take1 = (dp[i+1][1] != -1) ? dp[i+1][1] : Solver(i+1, 1, s, dp);
            }
        }

        return dp[i][prev] = min(take0, take1);
    }

    int minFlipsMonoIncr(string s) {
        
        int n = s.size();

        vector<vector<int>> dp(n+1, vector<int>(2, -1));

        return Solver(0, 0, s, dp);
    }
};  