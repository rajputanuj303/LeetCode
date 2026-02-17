class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);

        dp[1] = 1;

        int i2 = 1, i3 = 1, i5 = 1;

        for(int i = 2; i<=n; i++){

            int imul2 = dp[i2]*2;
            int imul3 = dp[i3]*3;
            int imul5 = dp[i5]*5;

            int minVal = min({imul2, imul3, imul5});

            if(minVal == imul2) i2++;
            if(minVal == imul3) i3++;
            if(minVal == imul5) i5++;

            dp[i] = minVal;
        }
        return dp[n];
    }
};