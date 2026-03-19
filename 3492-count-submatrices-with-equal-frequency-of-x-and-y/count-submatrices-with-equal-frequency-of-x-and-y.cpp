class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        vector<vector<int>> X(m, vector<int>(n, 0));    
        vector<vector<int>> Y(m, vector<int>(n, 0)); 

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){

                X[i][j] = (grid[i][j] == 'X');
                Y[i][j] = (grid[i][j] == 'Y');

                if(i > 0){
                    
                    X[i][j] += X[i-1][j];
                    Y[i][j] += Y[i-1][j];

                }
                if(j > 0){

                    X[i][j] += X[i][j-1];
                    Y[i][j] += Y[i][j-1];

                }

                if(i > 0 && j > 0){

                    X[i][j] -= X[i-1][j-1];
                    Y[i][j] -= Y[i-1][j-1];

                }

                if(X[i][j] != 0 && X[i][j] == Y[i][j]) count++;
            }
        } 

        return count; 
    }
};