class Solution {
public:
    vector<vector<int>> dp;

    int Solver(int n, int e){
        if(e == 1 || n <= 1) return n;

        if(dp[n][e] != -1) return dp[n][e];

        int low = 1, high = n;
        int ans = INT_MAX;

        while(low <= high){
            int mid = (low + high) / 2;

            int broken = (dp[mid-1][e-1] != -1) ? dp[mid-1][e-1] : Solver(mid-1, e-1);
            int notbroken = (dp[n-mid][e] != -1) ? dp[n-mid][e] : Solver(n-mid, e);

            int temp = 1 + max(broken, notbroken);

            if(broken > notbroken) high = mid - 1;
            else low = mid + 1;
            
            ans = min(ans, temp);
        }

        return dp[n][e] = ans;
    }

    int superEggDrop(int k, int n) {
        dp.resize(n+1, vector<int>(k+1, -1));
        return Solver(n, k);
    }
};