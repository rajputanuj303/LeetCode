class Solution {
public:
    int n;
    vector<vector<int>> dp;
    vector<int> prefixSum;
    int Solver(int idx, int k, vector<int> &nums){
        if(k > nums.size()) return INT_MAX;
        if(k == 1){
            int sum = prefixSum[n-1];
            if(idx-1 >= 0) sum -= prefixSum[idx-1];
            return sum;
        }

        if(dp[idx][k] != -1) return dp[idx][k];

        int sum = 0;
        int mini = INT_MAX;

        for(int i = idx; i < nums.size(); i++){
            sum += nums[i];
            int next = (dp[i+1][k] != -1) ? dp[i+1][k-1] : Solver(i+1, k-1, nums);
            mini = min(mini, max(sum, next));
        }
        return dp[idx][k] = mini;
    }
    int splitArray(vector<int>& nums, int k) {
        n = nums.size();
        dp.resize(n+1, vector<int>(k+1, -1));

        prefixSum.resize(n, 0);
        prefixSum[0] = nums[0];

        for(int i = 1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        return Solver(0, k, nums);
    }
};