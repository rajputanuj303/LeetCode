class Solution {
public:
    int maxRotateFunction(vector<int>& nums) { 

        int n = nums.size();       

        int Fi = 0;
        int sum = 0;
        for(int i = 0; i<n; i++){
            Fi += (i*nums[i]);
            sum += nums[i];
        }

        int maxi = Fi;

        for(int i = 1; i<n; i++){
            Fi = Fi + (sum - n*nums[n-i]);
            maxi = max(maxi, Fi);
        }

        return maxi;
    }
};