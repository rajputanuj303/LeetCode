class Solution {
public:
    bool isSafePlace(int n, vector<string> &nQueens, int row, int col){
        for(int i = 0; i<n; i++){
            if(nQueens[i][col] == 'Q') return false;
            if(nQueens[row][i] == 'Q') return false;
        }
        
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
            if(nQueens[i][j] == 'Q') {
                return false;
            }
        }

        // Check upper-right diagonal for any queen
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++) {
            if(nQueens[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    int solver(int n, vector<string> nQueens, int row)
    {
        if(row == n){
            return 1;
        }

        int count = 0;

        for(int col = 0; col<n; col++){
            if(isSafePlace(n, nQueens, row, col) == true){
                nQueens[row][col] = 'Q';
                count += solver(n, nQueens, row+1);
                nQueens[row][col] = '.';
            }
        }
        return count;
    }

    int totalNQueens(int n) {

        vector<string> nQueens(n, string(n, '.'));
        return solver(n, nQueens, 0);
    }
};