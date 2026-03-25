class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        long long sum = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                sum += grid[i][j];
            }
        }

        long long horSum = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                horSum += grid[i][j];
            }

            if(horSum == sum - horSum) return true;
        }

        long long verSum = 0;

        for(int j = 0; j<n; j++){
            for(int i = 0; i<m; i++){
                verSum += grid[i][j];
            }

            if(verSum == sum - verSum) return true;
        }

        return false;
    }
};