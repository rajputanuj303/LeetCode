class Solution {
public:

    int Solver(int l, int r, int d, vector<int> &arr, vector<vector<vector<int>>> &dp){

        if(r-l+1 < d) return 1e9+7;
        if(d == 1){

            int maxD = 0;
            for(int i = l; i<=r; i++) maxD = max(maxD, arr[i]);

            return maxD;
        }

        if(dp[l][r][d] != -1) return dp[l][r][d];

        int mini = INT_MAX;
        int maxD = 0;

        for(int mid = l; mid<r; mid++){
            maxD = max(maxD, arr[mid]);
            int val = maxD + Solver(mid+1, r, d-1, arr, dp);
            mini = min(mini, val);
        }
        return dp[l][r][d] = mini;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        if(n < d) return -1;

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(d+1, -1)));

        return Solver(0, n-1, d, jobDifficulty, dp);
    }
};