class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closest = nums[0] + nums[1] + nums[2];

        for(int i = 0; i<n-2; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i+1, right = n-1;
            
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == target) return sum;

                if(abs(target-sum) < abs(target-closest)) closest = sum;
                
                if(sum < target){
                    left++;
                    while(left < right && nums[left] == nums[left-1]) left++;
                }else{
                    right--;
                    while(left < right && nums[right] == nums[right+1]) right--;
                }
            }
        }
        return closest;
    }
};
