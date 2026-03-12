class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    unordered_map<int, vector<int>> mpp;

    int Solver(int i, int j, vector<int>& nums1, vector<int>& nums2){
        
        if(i >= m || j >= n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int notpair = 0 + Solver(i+1, j, nums1, nums2);

        int pidx = -1;

        for(int idx : mpp[nums1[i]]){
            if(idx >= j){
                pidx = idx;
                break;
            }
        }
        
        int pair = 0;

        if(pidx != -1){
            pair = 1 + Solver(i+1, pidx+1, nums1, nums2);
        }

        return dp[i][j] = max(pair, notpair);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        m = nums1.size();
        n = nums2.size();
        dp.resize(m+1, vector<int>(n+1, -1));

        for(int j = 0; j<n; j++){
            mpp[nums2[j]].push_back(j);
        }

        return Solver(0, 0, nums1, nums2);
    }
};