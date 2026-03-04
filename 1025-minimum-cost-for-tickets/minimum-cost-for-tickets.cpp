class Solution {
public:
    int Solver(int i, int &n, vector<int>& days, vector<int>& costs, vector<int> &dp){

        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int j = i, k = i;
        while(j < n && days[j] < days[i]+7) j++;
        while(k < n && days[k] < days[i]+30) k++;
        
        int take1 = costs[0] + Solver(i+1, n, days, costs, dp);
        int take7  = costs[1] + Solver(j, n, days, costs, dp);
        int take30 = costs[2] + Solver(k, n, days, costs, dp);

        return dp[i] = min({take1, take7, take30});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();
        
        vector<int> dp(n+1, -1);

        return Solver(0, n, days, costs, dp);
    }
};