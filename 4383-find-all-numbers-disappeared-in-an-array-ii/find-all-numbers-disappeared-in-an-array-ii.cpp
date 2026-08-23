class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        int prev = lower;

        for(int x : nums) {
            if(x < lower) continue;
            if(x > upper) break;

            if(prev < x) {
                res.push_back({prev, x - 1});
            }

            prev = x + 1;
        }
        
        if(prev <= upper) {
            res.push_back({prev, upper});
        }

        return res;
    }
};