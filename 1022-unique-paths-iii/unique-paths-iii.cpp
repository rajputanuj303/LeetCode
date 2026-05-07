class Solution {
public:
    int m, n;
    vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    bool isValid(int i, int j, vector<vector<int>> &grid){
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1) return false;
        return true;
    }

    int Solver(int i, int j, int empty, vector<vector<int>> &grid){
        if(grid[i][j] == 2){
            if(empty == -1) return 1;
            return 0;
        }

        int temp = grid[i][j];
        grid[i][j] = -1;
        

        int sum = 0;
        
        for(auto [dx, dy] : dirs){
            int newi = i + dx;
            int newj = j + dy;

            if(isValid(newi, newj, grid)){
                    
                sum += Solver(newi, newj, empty-1, grid);
            }
        }

        grid[i][j] = temp;

        return sum;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();   
            
        int empty = 0;
        
        int si = -1, sj = -1;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    si = i;
                    sj = j;
                }
                if(grid[i][j] == 0) empty++;
            }
        }

        int res = Solver(si, sj, empty, grid);
        return res;
    }
};