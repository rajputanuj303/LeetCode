class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return false;

        vector<pair<int, int>> dirs = {{-2, -1}, {-1, -2}, {-2, +1}, {-1, +2}, 
                                       {+1, +2}, {+2, +1}, {+2, -1}, {+1, -2}};
        
        int n = grid.size();
        int i = 0, j = 0;
        int curr = 0;

        for(curr = 1; curr < n*n; curr++){

            int tempi = i, tempj = j;

            for(pair<int, int> &dir : dirs){
                int newi = i + dir.first;
                int newj = j + dir.second;

                if(newi >= 0 && newj >= 0 && newi < n && newj < n && grid[newi][newj] == curr){                    
                    i = newi;
                    j = newj;
                    break;
                }
            }

            if(i == tempi && j == tempj) return false;
        }

        return true;
    }
};