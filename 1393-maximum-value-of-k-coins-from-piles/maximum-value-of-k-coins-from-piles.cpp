class Solution {
public:
    int Solver(int i, int k, vector<vector<int>>& piles, vector<vector<int>> &dp){

        if(i == piles.size() || k <= 0) return 0;
        if(dp[i][k] != -1) return dp[i][k];

        long long nottake = 0 + Solver(i+1, k, piles, dp);

        long long take = 0;
        long long sum = 0;

        for(int j = 0; j<piles[i].size(); j++){
            if(k-j-1 >= 0){
                sum += piles[i][j];
                take = max(take, sum + Solver(i+1, k-j-1, piles, dp));
            }
        }

        return dp[i][k] = max(take, nottake);
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        int n = piles.size();

        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));

        return Solver(0, k, piles, dp);
    }
};