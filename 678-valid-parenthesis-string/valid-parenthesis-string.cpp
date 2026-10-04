class Solution {
public:
    bool checkValidString(string s) {

        int n = s.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        dp[n][0] = 1;

        for (int i = n - 1; i >= 0; i--) {

            for (int balanced = 0; balanced <= n; balanced++) {

                if (s[i] == '(') {

                    if (balanced + 1 <= n) dp[i][balanced] = dp[i + 1][balanced + 1];

                }
                else if (s[i] == ')') {

                    if (balanced > 0) dp[i][balanced] = dp[i + 1][balanced - 1];

                }
                else {

                    dp[i][balanced] = dp[i + 1][balanced];

                    if (balanced + 1 <= n) dp[i][balanced] |= dp[i + 1][balanced + 1];
                    if (balanced > 0) dp[i][balanced] |= dp[i + 1][balanced - 1];
                }
            }
        }

        return dp[0][0];
    }
};