class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> cumSum(m, vector<int>(n));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                cumSum[i][j] = mat[i][j];

                if(i-1 >= 0) cumSum[i][j] += cumSum[i-1][j];
                if(j-1 >= 0) cumSum[i][j] += cumSum[i][j-1];

                if(i-1 >= 0 && j-1 >= 0) cumSum[i][j] -= cumSum[i-1][j-1];

                // cout << cumSum[i][j] << " "; 
            }
            // cout << endl;
        }
        vector<vector<int>> answer(m, vector<int>(n));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){

                int minR = i-k, maxR = min(i+k, m-1);
                int minC = j-k, maxC = min(j+k, n-1);

                int sum = cumSum[maxR][maxC];

                if((minC-1 >= 0)) sum -= cumSum[maxR][minC-1];
                if((minR-1 >= 0)) sum -= cumSum[minR-1][maxC];

                if((minR-1 >= 0) && (minC-1 >= 0)) sum += cumSum[minR-1][minC-1];
                answer[i][j] = sum;
            }
        }
        return answer;
    }
};