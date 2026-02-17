class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> dp(n+1);
        dp[0] = 1;
        long long u2 = 0;
        long long u3 = 0;
        long long u5 = 0;

        for(int i = 1;i<n;i++){
            long long newU2 = dp[u2] * 2;
            long long newU3 = dp[u3] * 3;
            long long newU5 = dp[u5] * 5;

            long long newAns = min({newU2,newU3,newU5});
            if(newAns == newU2) u2++;
            if(newAns == newU3) u3++;
            if(newAns == newU5) u5++;

            dp[i] = newAns;
        }

        return dp[n-1];
    }
};