class Solution {
public:
    int findMax(int l, int r, vector<int> &arr){
        int maxi = 0;
        for(int i = l; i<=r; i++){
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }
    int Solver(int l, int r, int d, vector<int> &arr, vector<vector<vector<int>>> &dp){

        if(r-l+1 < d) return 1e9+7;
        if(d == 1) return findMax(l, r, arr);

        if(dp[l][r][d] != -1) return dp[l][r][d];

        int mini = INT_MAX;

        for(int mid = l; mid<r; mid++){
            int val = findMax(l, mid, arr) + Solver(mid+1, r, d-1, arr, dp);
            mini = min(mini, val);
        }
        return dp[l][r][d] = mini;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(d+1, -1)));

        int res = Solver(0, n-1, d, jobDifficulty, dp);

        if(res >= 1e9+7) return -1;
        return res;
    }
};