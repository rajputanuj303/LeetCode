class Solution {
public:
    vector<vector<int>> rotate90(vector<vector<int>> &mat){
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> rotated(m, vector<int>(n));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                rotated[i][j] = mat[n-j-1][i];

                // cout << rotated[i][j] << " ";
            }
            // cout << endl;
        }

        // cout << endl << endl;

        return rotated;
        
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        

        if(mat == target) return true;

        mat = rotate90(mat);

        if(mat == target) return true;
        
        mat = rotate90(mat);

        if(mat == target) return true;

        mat = rotate90(mat);

        if(mat == target) return true;

        return false;

    }
};