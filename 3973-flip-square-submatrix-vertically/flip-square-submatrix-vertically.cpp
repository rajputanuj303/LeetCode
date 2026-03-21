class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int j = y; j<(y+k) && j<n; j++){
            int a = x;
            int b = x+k-1;

            while(a < b){
                swap(grid[a++][j], grid[b--][j]);
            }
        }
        return grid;
    }
};