class Solution {
public:
    using ll = long long;

    int M, N;
    vector<vector<vector<ll>>> dp;

    ll Solver(int i, int j, int parity, vector<vector<int>> &waitCost){
        if(i >= M || j >= N) return 1e15+7;
        if(i == M-1 && j == N-1) return 0;
        

        if(dp[i][j][parity] != 1e15+7) return dp[i][j][parity];

        if(parity==1){ // Odd

            ll right = 1e15+7;
            if(j+1 < N) right = (i+1)*(j+1+1) + Solver(i, j+1, parity^1, waitCost);
            ll down = 1e15+7;
            if(i+1 < M) down = (i+1+1)*(j+1) + Solver(i+1, j, parity^1, waitCost);    

            return dp[i][j][parity] = min(right, down);

        }else{ // even            
            return dp[i][j][parity] = waitCost[i][j] + Solver(i, j, parity^1, waitCost);
        }
    }
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        M = m;
        N = n;
        dp.resize(m, vector<vector<ll>>(n, vector<ll>(2, 1e15+7)));
        return 1 + Solver(0, 0, 1, waitCost);
    }
};