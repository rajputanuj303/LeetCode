class Solution {
public:
    vector<long long> dp;
    int MOD = 1e9+7;
    long long Solver(long long n){
        if(n <= 0) return 0;
        if(dp[n] != -1) return dp[n];
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 5;

        return dp[n] = (((2*(Solver(n-1)%MOD)%MOD) + (Solver(n-3)%MOD))%MOD);
    }
    int numTilings(int n) {
        dp.resize(n+1, -1);
        return Solver(n);
    }
};