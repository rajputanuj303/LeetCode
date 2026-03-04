class Solution {
public:
    int Solver(int i, int t, int &n, vector<int> &arr, vector<vector<int>> &dp){

        if(i >= n) return 0;
        if(dp[i][t] != -1) return dp[i][t];

        int include = arr[i]*t + Solver(i+1, t+1, n, arr, dp);
        int exclude = Solver(i+1, t, n, arr, dp);

        return dp[i][t] = max(include, exclude);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return Solver(0, 1, n, satisfaction, dp);
    }
};