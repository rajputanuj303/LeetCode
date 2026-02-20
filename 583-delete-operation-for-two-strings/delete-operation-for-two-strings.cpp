class Solution {
public:

    vector<vector<int>> dp; // dp for memoization

    int Solver(int i, int j, int &m, int &n, string s1, string s2){

        if(i >= m) return n-j;
        if(j >= n) return m-i;

        if(dp[i][j] != -1) return dp[i][j];


        if(s1[i] == s2[j]){
            return dp[i][j] = Solver(i+1, j+1, m, n, s1, s2);
        }

        int del1 = 1 + Solver(i+1, j, m, n, s1, s2);
        int del2 = 1 + Solver(i, j+1, m, n, s1, s2);

        return dp[i][j] = min(del1, del2);
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        dp.resize(m+1, vector<int>(n+1, -1));        

        return Solver(0, 0, m, n, word1, word2);
    }
};