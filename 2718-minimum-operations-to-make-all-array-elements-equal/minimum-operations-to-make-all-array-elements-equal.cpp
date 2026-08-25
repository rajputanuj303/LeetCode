class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<long long> prefixSum = {0};

        for(int i = 0; i<n; i++){
            prefixSum.push_back(prefixSum.back() + 1LL * nums[i]);
        }


        vector<long long> res;


        for(int q : queries){

            int idx = lower_bound(nums.begin(), nums.end(), q) - nums.begin();
            long long leftSum = 1LL * idx * q - 1LL * prefixSum[idx];
            long long rightSum = 1LL * (prefixSum[n] - prefixSum[idx]) - 1LL * (n - idx) * q;

            res.push_back(leftSum + rightSum);
        }


        return res;
    }
};