class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        long long reqWinSum = totalSum - x;

        int n = nums.size();

        if (reqWinSum == 0) return n;
        if (reqWinSum < 0) return -1;

        int left = 0;
        long long winSum = 0;
        int maxWindow = -1;

        for (int right = 0; right < n; right++) {
            winSum += nums[right];

            while (left <= right && winSum > reqWinSum) {
                winSum -= nums[left++];
            }

            if (winSum == reqWinSum) {
                maxWindow = max(maxWindow, right - left + 1);
            }
        }

        return (maxWindow == -1) ? -1 : n - maxWindow;
    }
};
