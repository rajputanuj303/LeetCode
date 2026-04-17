class Solution {
public:
    int reverse(int num){
        int res = 0;

        while(num){
            res = res * 10 + (num % 10);
            num /= 10;
        }
        return res;
    }
    int minMirrorPairDistance(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, int> mpp;

        int res = INT_MAX;

        for(int i = n-1; i>=0; i--){
            int rev = reverse(nums[i]);
            
            if(mpp.count(rev)){
                res = min(res, mpp[rev] - i);
            }
            mpp[nums[i]] = i;
        }

        return (res == INT_MAX) ? -1 : res;
    }
};