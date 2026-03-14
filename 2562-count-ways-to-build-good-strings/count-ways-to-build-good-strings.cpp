class Solution {
public:
    vector<int> dp;
    int MOD = 1e9+7;

    long long Solver(int s, int l, int h, int z, int o){
        if(s > h) return 0;

        if(dp[s] != -1) return dp[s];

        long long count = 0;

        if(s >= l && s <= h) 
            count = 1;

        count = (count + Solver(s + z, l, h, z, o)) % MOD;
        count = (count + Solver(s + o, l, h, z, o)) % MOD;

        return dp[s] = count%MOD;
    }

    int countGoodStrings(int low, int high, int zero, int one) {

        dp.resize(high + 1, -1);
        return Solver(0, low, high, zero, one);
    }
};