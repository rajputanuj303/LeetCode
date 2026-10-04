class Solution {
public:
    int n;
    vector<vector<int>> dp;
    bool Solver(int i, string s, int balanced){
        if(i == n){
            if(balanced == 0) return true;
            return false;
        }

        if(balanced < 0) return false;

        if(dp[i][balanced] != -1) return dp[i][balanced];

        bool result = false;

        if(s[i] == '*'){
            result |= Solver(i+1, s, balanced);
            result |= Solver(i+1, s, balanced+1);
            result |= Solver(i+1, s, balanced-1);
        }else{
            result |= Solver(i+1, s, balanced + (s[i] == '(' ? 1 : -1));
        }

        return dp[i][balanced] = result;
    }
    bool checkValidString(string s) {
        n = s.size();

        dp.assign(n+1, vector<int>(n+1, -1));
        return Solver(0, s, 0);
    }
};