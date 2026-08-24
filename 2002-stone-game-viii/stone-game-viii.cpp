class Solution {
public:
    int n;
    vector<int> prefix;
    vector<int> dp;

    int Solver(int i) {
        if (i == n - 2) return prefix[n - 1];
        if (dp[i] != INT_MIN) return dp[i];

        return dp[i] = max(Solver(i + 1), prefix[i + 1] - Solver(i + 1));
    }

    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();

        prefix.resize(n);
        dp.assign(n, INT_MIN);

        prefix[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        return Solver(0);
    }
};