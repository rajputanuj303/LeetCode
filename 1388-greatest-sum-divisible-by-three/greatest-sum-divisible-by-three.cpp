class Solution {
public:
    vector<vector<int>> dp;

    int Solver(int i, int rem, vector<int>& nums) {
        if(i == nums.size()) {
            return rem == 0 ? 0 : -1e9;
        }

        if(dp[i][rem] != -1) return dp[i][rem];

        int notTake = Solver(i + 1, rem, nums);

        int take = nums[i] +
                   Solver(i + 1, (rem + nums[i]) % 3, nums);

        return dp[i][rem] = max(notTake, take);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int>(3, -1));

        return Solver(0, 0, nums);
    }
};