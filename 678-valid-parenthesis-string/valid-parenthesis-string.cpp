class Solution {
public:

    bool Solver(int i, string &s, int balanced, int &n, vector<vector<int>> &dp) {

        if (balanced < 0) return false;
        if (balanced > n - i) return false;

        if (i == n)
            return balanced == 0;

        if (dp[i][balanced] != -1)
            return dp[i][balanced];

        bool result = false;

        if (s[i] == '*') {

            result = Solver(i + 1, s, balanced, n, dp);
            if (!result) result = Solver(i + 1, s, balanced + 1, n, dp);
            if (!result && balanced > 0) result = Solver(i + 1, s, balanced - 1, n, dp);

        } else {

            int newBalance = balanced + (s[i] == '(' ? 1 : -1);
            result = Solver(i + 1, s, newBalance, n, dp);
        }

        return dp[i][balanced] = result;
    }

    bool checkValidString(string s) {

        int n = s.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return Solver(0, s, 0, n, dp);
    }
};