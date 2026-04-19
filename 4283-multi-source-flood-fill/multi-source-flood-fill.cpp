class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        

        vector<vector<int>> res(n, vector<int>(m, 0));
        vector<vector<int>> time(n, vector<int>(m, -1));

        queue<pair<int, int>> que;

        for(vector<int> &v : sources){
            
            int i = v[0], j = v[1], color = v[2];

            res[i][j] = color;
            time[i][j] = 0;

            que.push({i, j});
        }

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!que.empty()){
            int s = que.size();

            while(s--){
                int i = que.front().first;
                int j = que.front().second;
                que.pop();

                int currtime = time[i][j];
                int currColor = res[i][j];

                for(pair<int, int> &dir : dirs){
                    int newi = i + dir.first;
                    int newj = j + dir.second;

                    if(newi >= 0 && newj >= 0 && newi < n && newj < m){

                        if(time[newi][newj] == -1){

                            time[newi][newj] = currtime+1;
                            res[newi][newj] = currColor;
                            que.push({newi, newj});

                        }
                        else if(time[newi][newj] == currtime+1){
                            res[newi][newj] = max(res[newi][newj], currColor);
                        }
                    }
                }
            }
        }
        
        return res;
    }
};