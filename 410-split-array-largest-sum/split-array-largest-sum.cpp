class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int Solver(int idx, int k, vector<int> &nums){
        if(k > nums.size()) return INT_MAX;
        if(k == 1){
            int sum = 0;
            for(int i = idx; i<nums.size(); i++){
                sum += nums[i];
            }
            return sum;
        }

        if(dp[idx][k] != -1) return dp[idx][k];

        int sum = 0;
        int mini = INT_MAX;

        for(int i = idx; i < nums.size(); i++){
            sum += nums[i];
            int next = Solver(i+1, k-1, nums);
            mini = min(mini, max(sum, next));
        }
        return dp[idx][k] = mini;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        dp.resize(n+1, vector<int>(k+1, -1));
        return Solver(0, k, nums);
    }
};