class Solution {
public:
    bool Solver(int i, string s, int balanced, int &n, vector<vector<int>> &dp){
        
        if(i == n){
            if(balanced == 0) return true;
            return false;
        }

        if(balanced < 0) return false;

        if(dp[i][balanced] != -1) return dp[i][balanced];

        bool result = false;

        if(s[i] == '*'){
            result |= Solver(i+1, s, balanced, n, dp);
            result |= Solver(i+1, s, balanced+1, n, dp);
            result |= Solver(i+1, s, balanced-1, n, dp);
        }else{
            result |= Solver(i+1, s, balanced + (s[i] == '(' ? 1 : -1), n, dp);
        }

        return dp[i][balanced] = result;
    }
    bool checkValidString(string s) {

        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return Solver(0, s, 0, n, dp);
    }
};