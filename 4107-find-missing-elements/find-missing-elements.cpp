class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> res;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) continue; // handle duplicates

            for (int x = nums[i - 1] + 1; x < nums[i]; x++) {
                res.push_back(x);
            }
        }

        return res;
    }
};