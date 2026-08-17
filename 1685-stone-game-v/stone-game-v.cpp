class Solution {
public:
    vector<int> prefixSum;
    vector<vector<int>> dp;
    int n;

    int Solver(int l, int r){
        if(l == r) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        int maxResult = 0;

        for(int mid = l; mid < r; mid++){
            int leftSum = prefixSum[mid] - (l  > 0 ? prefixSum[l-1] : 0);
            int rightSum = prefixSum[r] - prefixSum[mid];

            int currSum = 0;

            if(leftSum == rightSum){
                int leftPart = Solver(l, mid);
                int rightPart = Solver(mid+1, r);
                currSum = leftSum + max(leftPart, rightPart);

            }else if(leftSum > rightSum){

                int rightPart = Solver(mid+1, r);
                currSum = rightSum + rightPart;
                
            }else{

                int leftPart = Solver(l, mid);
                currSum = leftSum + leftPart;
            }

            maxResult = max(maxResult, currSum);
        }

        return dp[l][r] = maxResult;
    }
    int stoneGameV(vector<int>& stoneValue) {
        n = stoneValue.size();
        prefixSum.assign(n, 0);
        dp.assign(n, vector<int>(n, -1));

        prefixSum[0] = stoneValue[0];
        for(int i = 1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + stoneValue[i];
        }

        return Solver(0, n-1);        
    }
};