class Solution {
public:
    int Solver(int n, int e, vector<vector<int>> &dp){
        if(e <= 1 || n <= 1) return n;

        if(dp[n][e] != -1) return dp[n][e];

        int minRes = INT_MAX;  

        int low = 1, high = n;      

        while(low <= high){

            int mid = low + (high-low)/2;

            int broken = Solver(mid-1, e-1, dp);
            int notbroken = Solver(n-mid, e, dp);

            int temp = 1 + max(broken, notbroken);
            minRes = min(minRes, temp);
            
            if(broken > notbroken) high = mid - 1;
            else low = mid + 1;
        }

       
           
        return dp[n][e] = minRes;
    }

    int twoEggDrop(int n) {
        vector<vector<int>> dp(n+1, vector<int>(3, -1));
        return Solver(n, 2, dp);
    }
};