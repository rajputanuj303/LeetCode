class Solution {
public:
    int m, n;
    int MOD = 1e9+7;
    typedef long long ll;

    vector<vector<pair<ll, ll>>> dp;

    // returns {maxPos, minNeg}
    pair<ll, ll> Solver(int i, int j, vector<vector<int>> &grid){
        if(i == m-1 && j == n-1){
            return {grid[i][j], grid[i][j]};
        }

        if(dp[i][j].first != LLONG_MIN) return dp[i][j];

        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;

        if(i+1 < m){

            pair<ll, ll> down = Solver(i+1, j, grid);

            maxVal = max({maxVal, grid[i][j]*down.first, grid[i][j]*down.second});
            minVal = min({minVal, grid[i][j]*down.first, grid[i][j]*down.second});

        }

        if(j+1 < n){

            pair<ll, ll> right = Solver(i, j+1, grid);

            maxVal = max({maxVal, grid[i][j]*right.first, grid[i][j]*right.second});
            minVal = min({minVal, grid[i][j]*right.first, grid[i][j]*right.second});


        }
        
        return dp[i][j] = {maxVal, minVal};
    }
    int maxProductPath(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        dp.resize(m+1, vector<pair<ll, ll>>(n+1, {LLONG_MIN, LLONG_MAX}));

        pair<ll, ll> res = Solver(0, 0, grid);

        return (res.first >= 0) ? res.first%MOD : -1;
    }
};