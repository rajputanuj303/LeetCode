class Solution {
public:
    vector<vector<int>> dp;

    int Solver(int i, int j, string &s1, string &s2){
        if(i < 0 && j<0) return 0;
        if(i < 0) return j+1;
        if(j < 0) return i+1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) return dp[i][j] = Solver(i-1, j-1, s1, s2);
        
        
        int inserted = 1 + Solver(i, j-1, s1, s2);
        int deleted = 1 + Solver(i-1, j, s1, s2);
        int replaced = 1 + Solver(i-1, j-1, s1, s2);
        
        return dp[i][j] = min({inserted, deleted, replaced});
    }
    int minDistance(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        
        dp.resize(m+1, vector<int>(n+1, -1));
            
        return Solver(m-1, n-1, s1, s2);
    }
};