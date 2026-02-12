class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> answer(m, vector<int>(n));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){

                int minR = max(i-k, 0), maxR = min(i+k, m-1);
                int minC = max(j-k, 0), maxC = min(j+k, n-1);

                int sum = 0;

                for(int x = minR; x <= maxR; x++){
                    for(int y = minC; y<=maxC; y++) sum += mat[x][y];
                }                
                answer[i][j] = sum;
            }
        }
        return answer;
    }
};