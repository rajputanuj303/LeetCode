class Solution {
public:

    int n;
    vector<vector<int>> dp;
    bool Solver(int i, int target, vector<int> &nums){
        if(target == 0) return true;
        if(target < 0 || i >= n) return false;
        if(dp[i][target] != -1) return dp[i][target];

        bool take = Solver(i+1, target - nums[i], nums);
        bool nottake = Solver(i+1, target, nums);
        return dp[i][target] = take||nottake;
    }
    bool canPartition(vector<int>& nums) {

        int totalSum = 0;
        n = nums.size();

        for(int i : nums) totalSum += i;

        if(totalSum&1) return false;

        int target = totalSum/2;

        dp.resize(n+1, vector<int>(target+1, -1));

        return Solver(0, target, nums);
    }
};