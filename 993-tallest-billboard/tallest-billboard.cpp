class Solution {
public:
    int n;

    int Solver(int i, int diff, vector<int> &rods, vector<unordered_map<int, int>> &dp){
        if(i == n){
            if(diff == 0) return 0;
            return -1e9;
        }

        if(dp[i].count(diff)) return dp[i][diff];

        int addl1 = rods[i] + Solver(i+1, diff+rods[i], rods, dp);
        int addl2 = rods[i] + Solver(i+1, diff-rods[i], rods, dp);
        int  skip = Solver(i+1, diff, rods, dp);

        return dp[i][diff] = max({addl1, addl2, skip});
    }
    int tallestBillboard(vector<int>& rods) {
        n = rods.size();

        vector<unordered_map<int, int>> dp(n);
        return Solver(0, 0, rods, dp) / 2;
    }
};