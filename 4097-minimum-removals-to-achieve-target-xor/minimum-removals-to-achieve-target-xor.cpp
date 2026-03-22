class Solution {
public:
    
    vector<unordered_map<int, int>> dp;
    
    int Solver(int i, int cXor, int target, vector<int> &nums){
        if(i == nums.size()){
            return (cXor == target) ? 0 : 1e9;
        }

        if(dp[i].count(cXor)) return dp[i][cXor];

        int take = Solver(i+1, cXor^nums[i], target, nums);
        int nottake = 1 + Solver(i+1, cXor, target, nums);

        return dp[i][cXor] = min(take, nottake);
    }
    int minRemovals(vector<int>& nums, int target) {

        int n = nums.size();

        dp.resize(n, unordered_map<int, int>());
        
        int res = Solver(0, 0, target, nums);

        return (res == 1e9) ? -1 : res;
    }
};