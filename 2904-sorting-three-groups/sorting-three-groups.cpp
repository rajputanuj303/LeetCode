class Solution {
public:
    int n;
    map<pair<int,int>, int> dp;

    int Solver(int i, int last, vector<int>& nums) {

        if (i == n) return 0;

        if (dp.count({i, last}))
            return dp[{i, last}];

        // delete nums[i]
        int ans = 1 + Solver(i + 1, last, nums);

        // keep nums[i]
        if (nums[i] >= last)
            ans = min(ans, Solver(i + 1, nums[i], nums));

        return dp[{i, last}] = ans;
    }

    int minimumOperations(vector<int>& nums) {

        n = nums.size();
        return Solver(0, INT_MIN, nums);
    }
};