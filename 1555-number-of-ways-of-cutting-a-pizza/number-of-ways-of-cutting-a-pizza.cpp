class Solution {
public:

    vector<vector<int>> freq;
    vector<vector<vector<int>>> dp;
    int MOD = 1e9+7;

    int Solver(int hidx, int vidx, int cut, vector<string> &pizza){

        if(freq[hidx][vidx] == 0) return 0; // No apples existed
        if(cut == 0) return 1; // successfully found an required formation

        if(dp[hidx][vidx][cut] != -1) return dp[hidx][vidx][cut];

        int count = 0;
        int m = pizza.size();
        int n = pizza[0].size();

        // horizontal cuts
        for(int i = hidx; i < m-1; i++){
            // it checks whether there is an apple above and below the ith horizontal cut 
            if(freq[hidx][vidx] > freq[i+1][vidx] && freq[i+1][vidx] > 0){ 
                count = (count%MOD + Solver(i+1, vidx, cut-1, pizza)%MOD)%MOD;
            }
        }

        // vertical cuts
        for(int j = vidx; j < n-1; j++){
            // it checks whether there is an apple above and below the jth vertical cut
            if(freq[hidx][vidx] > freq[hidx][j+1]  && freq[hidx][j+1] > 0){ 
                count = (count%MOD + Solver(hidx, j+1, cut-1, pizza)%MOD)%MOD;
            }
        }

        return dp[hidx][vidx][cut] = count;
    }

    int ways(vector<string>& pizza, int k) {

        int m = pizza.size();
        int n = pizza[0].size();
        
        freq.resize(m+1, vector<int>(n+1, 0));        

        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(pizza[i][j] == 'A'){
                    freq[i][j] = 1 + freq[i+1][j] + freq[i][j+1] - freq[i+1][j+1];
                }else{
                    freq[i][j] = freq[i+1][j] + freq[i][j+1] - freq[i+1][j+1];
                }
            }
        }

        dp.resize(m+1, vector<vector<int>>(n+1, vector<int>(k+1, -1)));

        return Solver(0, 0, k-1, pizza);
    }
};