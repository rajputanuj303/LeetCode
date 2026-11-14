class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> a(n + 1, 0);

        for (int i = 1; i <= n; i++)
            a[i] = nums[i - 1] + a[i - 1];

        int mini = INT_MAX;

        for (int i = l; i <= n; i++) {
            for (int j = max(0, i - r); j <= i - l; j++) {
                int sum = a[i] - a[j];

                if (sum > 0)
                    mini = min(mini, sum);
            }
        }

        return mini == INT_MAX ? -1 : mini;
    }
};