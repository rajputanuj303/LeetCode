class Solution {
public:
    // first 1, 2
    // second 1,2,3,4,5,6,7,8,9
    bool isValid(string str){
        
        if(str.size() == 1){
            if(str[0] == '0') return false;
            return true;
        }else if(str.size() == 2){
            if(str[0] == '1') return true;
            else if(str[0] == '2'){
                if(str[1] >= '0' && str[1] <= '6') return true;
                return false;
            }
        }
        return false;
    }

    int Solver(int i, int &n, string s, vector<int> &dp){
        if(i >= n) return 1;
        if(dp[i] != -1) return dp[i];

        string str;

        int res = 0;

        for(int j = i; j<n; j++){
            str.push_back(s[j]);
            if(isValid(str)){
                res += Solver(j+1, n, s, dp);
            } else break;
        } 

        return dp[i] = res;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        
        return Solver(0, n, s, dp);
    }
};