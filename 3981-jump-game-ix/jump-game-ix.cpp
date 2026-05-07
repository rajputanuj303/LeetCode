class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> prefixMax(n);
        vector<int> suffixMin(n);

        prefixMax[0] = nums[0];
        suffixMin[n-1] = nums[n-1];

        for(int i = 1; i<n; i++){
            prefixMax[i] = max(prefixMax[i-1], nums[i]);
            suffixMin[n-i-1] = min(suffixMin[n-i], nums[n-i-1]);
        }

        vector<int> res(n);
        res[n-1] = prefixMax[n-1];

        for(int i = n-2; i>=0; i--){
            if(prefixMax[i] > suffixMin[i+1]){
                res[i] = res[i+1];
            }else{
                res[i] = prefixMax[i];
            }
        }

        return res;
    }
};