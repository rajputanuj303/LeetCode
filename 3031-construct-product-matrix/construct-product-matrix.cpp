class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int MOD = 12345;

        vector<int> flatten;

        // flatten into 1D array
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                flatten.push_back(grid[i][j]);
            }
        }

        int s = flatten.size();

        vector<int> preMul(s, 1), sufMul(s, 1);

        // prefix and suffix
        for(int i = 1; i < s; i++){
            preMul[i] = ((long long)preMul[i-1] * flatten[i-1]) % MOD;
            sufMul[s-i-1] = ((long long)sufMul[s-i] * flatten[s-i]) % MOD;
        }

        int idx = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                grid[i][j] = ((long long)preMul[idx] * sufMul[idx])%MOD;
                idx++;
            }
        }

        return grid;
    }
};