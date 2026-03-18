class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> prefixSum(m, vector<int>(n, 0));

        prefixSum[0][0] = grid[0][0];

        for(int i = 1; i<m; i++) prefixSum[i][0] = prefixSum[i-1][0] + grid[i][0];
        for(int j = 1; j<n; j++) prefixSum[0][j] = prefixSum[0][j-1] + grid[0][j];

        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + grid[i][j];
            }
        }

        int count = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(prefixSum[i][j] <= k){
                    count++;
                }
            }
        }

        return count;
        
    }
};