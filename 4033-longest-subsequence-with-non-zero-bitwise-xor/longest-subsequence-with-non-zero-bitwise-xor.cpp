class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int totalXor = 0;
        bool nonZero = false;

        for (int &x : nums){
            totalXor ^= x;
            if(x != 0) nonZero = true;
        }

        if(totalXor != 0) return n;
        if(nonZero) return n-1;
        return 0;
    }
};