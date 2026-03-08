class Solution {
public:
    int solver(int i, int buy, int limit, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(i >= prices.size() || limit == 0) return 0;
        if(dp[i][buy][limit] != -1) return dp[i][buy][limit];
        if(buy == 1){
            int bought = -prices[i] + solver(i+1, 0, limit, prices, dp);
            int notBought = 0 + solver(i+1, 1, limit, prices, dp);
            return dp[i][buy][limit] = max(bought, notBought);
        }
        int sell = prices[i] + solver(i+1, 1, limit-1, prices, dp);
        int notSell = 0 + solver(i+1, 0, limit, prices, dp);
        return dp[i][buy][limit] = max(sell, notSell);
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));

        return solver(0, 1, k, prices, dp);
    }
};