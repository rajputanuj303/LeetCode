class Solution {
public:
    int n;
    vector<int> dp;

    int solve(int idx, vector<int>& stoneValue) {
        if (idx >= n) return 0;

        if (dp[idx] != INT_MIN)
            return dp[idx];

        int take = 0;
        int best = INT_MIN;

        for (int i = idx; i < min(n, idx + 3); i++) {
            take += stoneValue[i];
            best = max(best, take - solve(i + 1, stoneValue));
        }

        return dp[idx] = best;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.assign(n, INT_MIN);

        int diff = solve(0, stoneValue);

        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};