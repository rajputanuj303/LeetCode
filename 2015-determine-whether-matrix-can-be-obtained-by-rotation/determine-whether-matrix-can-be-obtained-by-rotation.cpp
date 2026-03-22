class Solution {
public:
    void rotate90(vector<vector<int>> &mat){
        
        int n = mat.size();
        
        //Transpose
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }

        //row-reverse
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n/2; j++){
                swap(mat[i][j], mat[i][n-j-1]);
            }
        }
        
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        

        if(mat == target) return true;

        rotate90(mat); // rotate once

        if(mat == target) return true;
        
        rotate90(mat); // rotate twice

        if(mat == target) return true;

        rotate90(mat); // rotate thrice

        if(mat == target) return true;

        return false;

    }
};