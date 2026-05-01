class Solution {
public:
    int maxRotateFunction(vector<int>& nums) { 

        int n = nums.size();       

        int prevF = 0;
        int sum = 0;
        for(int i = 0; i<n; i++){
            prevF += (i*nums[i]);
            sum += nums[i];
        }

        int maxi = prevF;

        for(int i = 1; i<n; i++){
            int currF = prevF + (sum - n*nums[n-i]);
            maxi = max(maxi, currF);
            prevF = currF;
        }

        return maxi;
    }
};