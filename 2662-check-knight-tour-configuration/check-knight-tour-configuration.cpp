class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return false;

        int n = grid.size();

        queue<pair<int, int>> que;
        que.push({0, 0});

        vector<pair<int, int>> dirs = {{-2, -1}, {-1, -2}, {-2, +1}, {-1, +2}, 
                                       {+1, +2}, {+2, +1}, {+2, -1}, {+1, -2}};
        
        int curr = 0;
        while(!que.empty()){
            int i = que.front().first;
            int j = que.front().second;
            que.pop();

            for(pair<int, int> dir : dirs){
                int newi = i + dir.first;
                int newj = j + dir.second;

                if((newi >= 0 && newj >= 0 && newi < n && newj < n) && grid[newi][newj] == curr+1){
                    que.push({newi, newj});
                    curr++;
                    break;
                }
            }
        }

        return curr == n*n-1;
    }
};