class Solution {
public:
    int n;
    int LIS(int i, int prevIdx, vector<int> &nums, vector<vector<int>> &dp){

        if(i == n) return 0;

        if(prevIdx != -1 && dp[i][prevIdx] != -1) return dp[i][prevIdx]; 

        int take = 0;
        if(prevIdx == -1 || nums[i] > nums[prevIdx]){
            take = 1 + LIS(i+1, i, nums, dp);
        }

        int nottake = LIS(i+1, prevIdx, nums, dp);

        if(prevIdx != -1){
            dp[i][prevIdx] = max(take, nottake);
        }

        return max(take, nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return LIS(0, -1, nums, dp);
    }
};