class Solution {
public:
    vector<int> dp;
    int MOD = 1e9+7;

    long long Solver(int s, int l, int h, int z, int o){
        if(s > h) return 0;

        if(dp[s] != -1) return dp[s];

        int count = 0;

        if(s+z >= l && s+z <= h){
            count = 1 + (Solver(s+z, l, h, z, o)%MOD);
        }else{
            count = Solver(s+z, l, h, z, o)%MOD;
        }

        if(s+o >= l && s+o <= h){
            count += (1 + Solver(s+o, l, h, z, o))%MOD;
        }else{
            count = (count%MOD + Solver(s+o, l, h, z, o)%MOD)%MOD;
        }

        return dp[s] = count%MOD;
    }

    int countGoodStrings(int low, int high, int zero, int one) {

        dp.resize(high + 1, -1);
        return Solver(0, low, high, zero, one);
    }
};