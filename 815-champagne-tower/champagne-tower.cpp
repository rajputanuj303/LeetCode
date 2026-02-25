class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

        vector<vector<double>> dp(query_row+1, vector<double>(query_glass+2, 0.0));

        dp[0][0] = poured * 1.0;

        int r = 0;
        bool overflow = true;

        while(r < query_row && overflow) {   // ✅ fixed
            overflow = false;

            for(int c = 0; c <= query_glass; c++) {   // ✅ fixed
                if(dp[r][c] > 1.0) {
                    overflow = true;

                    double rem = dp[r][c] - 1.0;

                    dp[r+1][c] += rem / 2.0;
                    dp[r+1][c+1] += rem / 2.0;

                    dp[r][c] = 1.0;
                }
            }
            r++;
        }

        return min(1.0, dp[query_row][query_glass]);  // ✅ clamp
    }
};