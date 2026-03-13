class Solution {
public:
    int n;
    vector<long long> dp;

    long long Solver(int i, vector<vector<int>> &questions){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        long long notpick = Solver(i+1, questions);
        long long pick = questions[i][0] + Solver(i+questions[i][1]+1, questions);

        return dp[i] = max(pick, notpick);
    }


    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        dp.resize(n+1, -1);
        return Solver(0, questions);
    }
};