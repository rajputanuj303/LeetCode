class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        
        int m = s1.size();
        int n = s2.size();

        // cout << int('a') << endl;

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = 1; i <= m; i++) dp[i][0] = int(s1[i-1]) + dp[i-1][0];
        for(int j = 1; j <= n; j++) dp[0][j] = int(s2[j-1]) + dp[0][j-1];

        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    int take1 = int(s1[i-1]) + dp[i-1][j];
                    int take2 = int(s2[j-1]) + dp[i][j-1];

                    dp[i][j] = min(take1, take2);
                }
            }
        }

        return dp[m][n];
    }
};