class Solution {
public:
    bool isValid(int limit, int k, vector<int> &nums){

        int st = 1, pagesAll = 0;
        for(int i = 0; i<nums.size(); i++){
            if(pagesAll + nums[i] <= limit){
                pagesAll += nums[i];
            }else{
                pagesAll = nums[i];
                st++;
            }            
        }

        return st <= k;
    }
    int splitArray(vector<int>& nums, int k) {

        int n = nums.size();
        int low = 0;
        int high = 0;

        for(int i = 0; i<n; i++){
            low = max(low, nums[i]);
            high += nums[i];
        }

        int res = high;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isValid(mid, k, nums)){
                res = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }

        }

        return res;
    }
};