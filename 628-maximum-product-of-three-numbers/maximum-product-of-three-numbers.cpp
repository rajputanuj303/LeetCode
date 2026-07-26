class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int maxi = nums[n-1]*nums[n-2]*nums[n-3];
        maxi = max(maxi, nums[n-1]*nums[0]*nums[1]);
        maxi = max(maxi, nums[0]*nums[n-1]*nums[n-2]);
        maxi = max(maxi, nums[0]*nums[1]*nums[2]);
        return maxi;
    }
};