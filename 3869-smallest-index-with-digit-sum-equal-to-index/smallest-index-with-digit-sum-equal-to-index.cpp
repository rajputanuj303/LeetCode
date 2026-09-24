class Solution {
public:
    int smallestIndex(vector<int>& nums) {

        int n = nums.size();

        for(int i = 0; i<n; i++){
            int digitSum = 0;
            while(nums[i] != 0){
                digitSum += (nums[i]%10);
                nums[i] /=10;
            }

            if(digitSum == i) return i;
        }
        
        return -1;
    }
};