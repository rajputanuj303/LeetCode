class Solution {
public:
    static bool cmp(vector<int> &u, vector<int> &v){
        return u[2] > v[2];
    }
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        

        vector<vector<int>> res(n, vector<int>(m, 0));

        queue<pair<int, int>> que;

        sort(sources.begin(), sources.end(), cmp);

        for(vector<int> &v : sources){
            
            int i = v[0], j = v[1], color = v[2];
            res[i][j] = color;
            que.push({i, j});
        }

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!que.empty()){

            int s = que.size();
            while(s--){
                int i = que.front().first;
                int j = que.front().second;
                que.pop();

                int currColor = res[i][j];

                for(pair<int, int> &dir : dirs){
                    int newi = i + dir.first;
                    int newj = j + dir.second;

                    if(newi >= 0 && newj >= 0 && newi < n && newj < m){

                        if(res[newi][newj] == 0){
                            
                            res[newi][newj] = currColor;
                            que.push({newi, newj});
                        }
                    }
                }
            }
        }
        
        return res;
    }
};