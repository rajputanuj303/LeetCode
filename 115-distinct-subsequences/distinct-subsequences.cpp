class Solution {
public:
    int m, n;
    vector<vector<long long>> dp;

    long long Solver(int i, int j, string &s, string &t){
        if(j == n) return 1;
        if(i == m) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        long long count = 0;

        if(s[i] == t[j]){
            count += Solver(i+1, j+1, s, t); // take
        }

        count += Solver(i+1, j, s, t); // skip

        return dp[i][j] = count;
    }

    int numDistinct(string s, string t) {
        m = s.size();
        n = t.size();
        dp.assign(m, vector<long long>(n, -1));
        return Solver(0, 0, s, t);
    }
};