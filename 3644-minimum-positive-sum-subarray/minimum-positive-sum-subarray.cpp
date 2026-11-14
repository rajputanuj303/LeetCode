class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int n = nums.size();
        int minimum = INT_MAX;
        
        for(int i = 0; i<n; i++){
            int sum = 0;
            for(int j = i; j<n; j++){
                sum += nums[j];
                int window = j - i + 1;
                if(sum > 0 && window >= l && window <= r){
                    minimum = min(minimum, sum);
                }
            }
        }
        
    
        return (minimum == INT_MAX) ? -1 : minimum;

    }
};