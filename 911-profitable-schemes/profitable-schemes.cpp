class Solution {
public:
    vector<vector<vector<int>>> dp;
    const int MOD = 1e9+7;

    int Solver(int i, int n, int minProfit,
               vector<int>& group, vector<int>& profit){

        if(i == group.size()){
            return (minProfit <= 0) ? 1 : 0;
        }

        if(dp[i][n][minProfit] != -1) return dp[i][n][minProfit];

        int nottake = Solver(i+1, n, minProfit, group, profit);

        int take = 0;
        if(group[i] <= n){
            take = Solver(i+1,
                          n - group[i],
                          max(0, minProfit - profit[i]),
                          group, profit);
        }

        return dp[i][n][minProfit] = (take + nottake) % MOD;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {

        int s = group.size();
        dp.resize(s+1, vector<vector<int>>(n+1, vector<int>(minProfit+1, -1)));
        return Solver(0, n, minProfit, group, profit);
    }
};