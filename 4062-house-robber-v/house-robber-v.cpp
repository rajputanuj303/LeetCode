class Solution {
public:
    vector<unordered_map<int, long long>> dp;
    long long Solver(int i, int &n, int prev, vector<int> &nums, vector<int> &colors){
        if(i >= n) return 0;
        if(dp[i].find(prev) != dp[i].end()) return dp[i][prev];
        
        long long take = 0;

        if(prev != colors[i]){
            take = nums[i] + Solver(i+1, n, colors[i], nums, colors);
        }

        long long nottake = 0 + Solver(i+1, n, 0, nums, colors);

        return dp[i][prev] = max(take, nottake);
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        
        int n = nums.size();
        int maxColor = 0;

        // for(int i : colors) maxColor = max(maxColor, i);

        dp.resize(n+1, unordered_map<int, long long>());
        return Solver(0, n, 0, nums, colors);
    }
};