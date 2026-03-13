class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        
        int n = questions.size();

        vector<long long> dp(n+1, 0);


        for(int i = n-1; i>= 0; i--){

            long long notpick = dp[i+1];
            long long pick = questions[i][0];            
            if(i+questions[i][1]+1 <= n) pick += dp[i+questions[i][1]+1];
            
            dp[i] = max(pick, notpick);

        }

        return dp[0];
    }
};