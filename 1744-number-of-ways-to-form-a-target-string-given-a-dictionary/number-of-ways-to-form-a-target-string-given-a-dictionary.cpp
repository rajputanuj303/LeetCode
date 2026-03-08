class Solution {
public:
    vector<vector<long long>> dp;
    vector<vector<long long>> freq;
    int MOD = 1e9+7;
    int Solver(int tidx, int cidx, vector<string>& words, string& target){

        if(tidx == target.size()) return 1;
        if(cidx == words[0].size()) return 0;

        if(dp[tidx][cidx] != -1) return dp[tidx][cidx];

        long long nottake = Solver(tidx, cidx+1, words, target)%MOD;

        long long count = freq[cidx][target[tidx]-'a'];

        long long take = ((Solver(tidx+1, cidx+1, words, target)%MOD)*(count%MOD))%MOD;

        return dp[tidx][cidx] = (take + nottake)%MOD;
    }

    int numWays(vector<string>& words, string target) {
        int n = target.size();
        int m = words[0].size();

        dp.assign(n+1, vector<long long>(m+1, -1));
        freq.resize(m+1, vector<long long>(26, 0));

        for(string &s : words){
            for(int i = 0; i<m; i++){
                freq[i][s[i]-'a']++;
            }
        }


        return Solver(0,0,words,target);
    }
};