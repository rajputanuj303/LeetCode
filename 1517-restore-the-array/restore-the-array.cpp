class Solution {
public:
    vector<int> dp;
    int MOD = 1e9+7;
    int n;
    int Solver(int idx, string &s, int k){
        if(idx == n) return 1;
        if(s[idx] == '0') return 0;

        if(dp[idx] != -1) return dp[idx];
    
        int count = 0;
        long long Lnum = 0;

        for(int i = idx; i<n; i++){

            Lnum = (Lnum*10) + int(s[i]-'0');

            // cout << Lnum << endl;

            if(Lnum >=1 && Lnum <= k){
                count = (count%MOD + Solver(i+1, s, k)%MOD)%MOD;
            }else break;
        }
        return dp[idx] = count;
    }

    int numberOfArrays(string s, int k) {

        n = s.size();
        dp.resize(n+1, -1);
        return Solver(0, s, k);
    }
};