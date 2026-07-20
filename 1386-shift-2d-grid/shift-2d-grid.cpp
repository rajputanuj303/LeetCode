class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();

        k = k % (m*n);

        if(k == 0) return grid;

        vector<vector<int>> res(m, vector<int>(n, 0));

        int x = (m*n - k) / n;
        int y = (m*n - k) % n;

        int ti = x, tj = y;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                res[i][j] = grid[ti][tj++];
                if(tj == n){
                    ti++;
                    tj = 0;
                }
                if(ti == m){
                    ti = 0;
                }
                cout << res[i][j] << " ";
            }
            cout << endl;
        }

        return res;
    }
};