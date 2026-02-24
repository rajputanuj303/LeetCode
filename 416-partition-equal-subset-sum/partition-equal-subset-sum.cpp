class Solution {
public:

    bool canPartition(vector<int>& nums) {

        int totalSum = 0;
        int n = nums.size();

        for(int i : nums) totalSum += i;
        if(totalSum&1) return false;
        int target = totalSum/2;

        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

        for(int i = 1; i<=n; i++){
            for(int j = 0; j<=target; j++){
                if(j == 0) dp[i][0] = 1;
                else{
                    if(j - nums[i-1] < 0) dp[i][j] = dp[i-1][j];
                    else dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }

            }
        }

        return dp[n][target];
    }
};