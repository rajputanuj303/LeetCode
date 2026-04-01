class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        int m = maze.size();
        int n = maze[0].size();
        
        vector<pair<int, int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}};
        queue<pair<int,int>> que;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        que.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;

        int steps = 0;

        while(!que.empty()){
            int sz = que.size();

            while(sz--){
                auto [i, j] = que.front();
                que.pop();

                if((i != entrance[0] || j != entrance[1]) &&
                   (i == 0 || i == m-1 || j == 0 || j == n-1)){
                    return steps;
                }

                for(auto [dx, dy] : dirs){
                    int ni = i + dx;
                    int nj = j + dy;

                    if(ni >= 0 && nj >= 0 && ni < m && nj < n &&
                       maze[ni][nj] == '.' && !visited[ni][nj]){
                        
                        visited[ni][nj] = true;
                        que.push({ni, nj});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};