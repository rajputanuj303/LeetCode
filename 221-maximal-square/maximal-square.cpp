class Solution {
public:
    int maximalSquare(vector<vector<char>>& arr) {


        int m = arr.size();
        int n = arr[0].size();
        

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        int maxSize = 0;

        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                if(i == m-1 || j == n-1){
                    if(arr[i][j] == '1') dp[i][j] = 1;
                    else dp[i][j] = 0;
                }else{
                    if(arr[i][j] == '1'){
                        dp[i][j] = min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]}) + 1;
                    }else{
                        dp[i][j] = 0;
                    }
                }                

                maxSize = max(dp[i][j], maxSize);
            }
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++) cout << dp[i][j] << " ";
            cout << endl;
        }
        return maxSize*maxSize;
    }
};