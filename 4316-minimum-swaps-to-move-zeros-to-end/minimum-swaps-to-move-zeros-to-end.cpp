class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = n-1;
        int count = 0;

        while(i < j){
            while(i < j && nums[j] == 0) j--;
            if(i >= j) break;
            if(nums[i] == 0){
                swap(nums[i], nums[j]);
                count++;
                j--;
            }
            i++;
        }

        return count;
    }
};