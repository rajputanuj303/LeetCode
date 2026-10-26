class Solution {
public:
    long long dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m)
            return 0;
        if (grid[i][j] == 0 || visited[i][j])
            return 0;

        visited[i][j] = true;

        long long sum = grid[i][j];


        sum += dfs(grid, visited, i - 1, j); // up
        sum += dfs(grid, visited, i + 1, j); // down
        sum += dfs(grid, visited, i, j - 1); // left
        sum += dfs(grid, visited, i, j + 1); // right

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0 && !visited[i][j]) {
                    long long sum = dfs(grid, visited, i, j);
                    if (sum % k == 0)
                        count++;
                }
            }
        }
        return count;
    }
};
