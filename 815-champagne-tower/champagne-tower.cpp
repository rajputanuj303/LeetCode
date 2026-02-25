class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        

        vector<vector<double>> dp(101, vector<double>(101, 0.0));

        dp[0][0] = poured*1.0;

        int r = 0;
        bool overflow = true;

        while(r <= 99 && overflow){
            
            overflow = false;
            for(int c = 0; c<=r; c++){

                if(dp[r][c] > 1.0){
                    overflow = true;

                    double rem = dp[r][c] - 1.0;

                    dp[r+1][c] += rem/2.0;
                    dp[r+1][c+1] += rem/2.0;

                    dp[r][c] = 1.0;
                }
            }
            r++;
        }

        // for(int i = 0; i<= 100; i++){
        //     for(int j = 0; j<=100; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return dp[query_row][query_glass];
    }
};