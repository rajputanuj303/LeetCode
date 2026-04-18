class Solution {
public:
    bool isSafePlace(int n, vector<vector<int>> &nQueens, int row, int col){
        for(int i = 0; i<n; i++){
            if(nQueens[i][col] == 1) return false;
            if(nQueens[row][i] == 1) return false;
        }
        
        int x = row, y = col;

        while(x >= 0 && y >= 0){
            if(nQueens[x--][y--]) return false;
        }

        x = row, y = col;
        while(x >= 0 && y < n){
            if(nQueens[x--][y++]) return false;
        }

        return true;
    }
    int solver(int n, vector<vector<int>> &nQueens, int row)
    {
        if(row == n){
            return 1;
        }

        int count = 0;

        for(int col = 0; col<n; col++){
            if(isSafePlace(n, nQueens, row, col) == true){
                nQueens[row][col] = 1;
                count += solver(n, nQueens, row+1);
                nQueens[row][col] = 0;
            }
        }
        return count;
    }

    int totalNQueens(int n) {

        vector<vector<int>> nQueens(n, vector<int>(n, 0));
        return solver(n, nQueens, 0);
    }
};