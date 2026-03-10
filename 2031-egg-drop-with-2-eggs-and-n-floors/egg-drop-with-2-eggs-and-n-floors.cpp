class Solution {
public:
    int Solver(int n, int e, vector<vector<int>> &dp){
        if(e <= 1 || n <= 1) return n;

        if(dp[n][e] != -1) return dp[n][e];

        int minRes = INT_MAX;        

        for(int i = 1; i<=n; i++){
            int broken = Solver(i-1, e-1, dp);
            int notbroken = Solver(n-i, e, dp);

            int temp = 1 + max(broken, notbroken);
            minRes = min(minRes, temp);
        }

       
           
        return dp[n][e] = minRes;
    }

    int twoEggDrop(int n) {
        vector<vector<int>> dp(n+1, vector<int>(3, -1));
        return Solver(n, 2, dp);
    }
};