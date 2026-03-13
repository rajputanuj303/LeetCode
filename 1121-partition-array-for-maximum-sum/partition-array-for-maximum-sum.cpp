class Solution {
public:
    vector<int> dp;
    int Solver(int idx, int n, vector<int> &arr, int k){
        if(idx >= n) return 0;

        if(dp[idx] != -1) return dp[idx];

        int maxi = 0;        
        int sum = 0;
        for(int i = idx; i < n && i < (idx+k); i++){
            maxi = max(maxi, arr[i]);
            sum =  max(sum, maxi*(i-idx+1) + Solver(i+1, n, arr, k));
        }
        return dp[idx] = sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        dp.resize(n+1, -1);
        return Solver(0, n, arr, k);
    }
};