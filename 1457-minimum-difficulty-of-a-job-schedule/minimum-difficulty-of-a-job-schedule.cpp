class Solution {
public:

    int Solver(int idx, int d, int &n, vector<int> &arr, vector<vector<int>> &dp){

        if(d == 1){
            int maxD = 0;
            for(int i = idx; i<n; i++) maxD = max(maxD, arr[i]);
            return maxD;
        }

        if(dp[idx][d] != -1) return dp[idx][d];

        int mini = INT_MAX;
        int maxD = 0;

        for(int i = idx; i <= n-d; i++){
            maxD = max(maxD, arr[i]);
            int val = maxD + Solver(i+1, d-1, n, arr, dp);
            mini = min(mini, val);
        }
        return dp[idx][d] = mini;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        if(n < d) return -1;

        vector<vector<int>> dp(n+1, vector<int>(d+1, -1));

        return Solver(0, d, n, jobDifficulty, dp);
    }
};