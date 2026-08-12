class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        if(k >= n) return n;

        int l = 0, r = 0;
        int longest = 0;
        unordered_map<int, int> freqMap;

        while(r < n){
            freqMap[nums[r]]++;
            while(freqMap[nums[r]] > k){
                freqMap[nums[l]]--;
                l++;
            }
            longest = max(longest, r-l+1);
            r++;
        }
        return longest;
    }
};