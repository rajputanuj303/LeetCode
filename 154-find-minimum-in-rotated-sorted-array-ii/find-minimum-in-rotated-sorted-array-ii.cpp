class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while(low < high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] > nums[high]) {
                // minimum in right half
                low = mid + 1;

            } else if(nums[mid] < nums[high]) {
                // minimum in left half including mid
                high = mid;

            } else {
                // nums[mid] == nums[high]
                // cannot decide, shrink search space
                high--;
            }
        }

        return nums[low];
    }
};