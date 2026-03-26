class Solution {
public:
    int n;
    int Solver(int idx, bool alice, int M, vector<int> &piles, vector<vector<vector<int>>> &dp){

        if(idx >= n) return 0;

        if(dp[idx][M][alice] != -1) return dp[idx][M][alice];

        int maxSum = (alice) ? -1 : INT_MAX;
 
        int stones = 0;

        for(int x = 1; x <= min(2*M, n-idx) ; x++){
            
            stones += piles[idx + x - 1];

            if(alice){

                maxSum = max(maxSum, stones + Solver(idx + x, 0, max(M, x), piles, dp));

            }else{

                maxSum = min(maxSum, Solver(idx + x, 1, max(M, x), piles, dp));

            }
        }

        return dp[idx][M][alice] = maxSum;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(201, vector<int>(2, -1)));
        return Solver(0, 1, 1, piles, dp);
    }
};