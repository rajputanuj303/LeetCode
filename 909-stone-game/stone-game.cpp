class Solution {
public:
    
    vector<vector<int>> dp;

    int Solver(int i, int j, vector<int> &piles){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int takeLeft  = piles[i] - Solver(i+1, j, piles);
        int takeRight = piles[j] - Solver(i, j-1, piles);

        return dp[i][j] = max(takeLeft, takeRight);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.resize(n+1, vector<int>(n+1, -1));
        
        return Solver(0, piles.size()-1, piles) > 0;
    }
};