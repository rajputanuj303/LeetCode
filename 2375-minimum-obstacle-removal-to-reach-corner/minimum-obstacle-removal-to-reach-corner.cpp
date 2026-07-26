class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> obs(m, vector<int>(n, INT_MAX));
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({grid[0][0], 0, 0});
        obs[0][0] = grid[0][0];


        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};


        while(!pq.empty()){

            vector<int> v = pq.top();
            pq.pop();

            int currObs = v[0];
            int i = v[1], j = v[2];

            for(int k = 0; k<4; k++){

                int ni = i + dr[k];
                int nj = j + dc[k];

                if(ni < 0 || nj < 0 || ni >= m || nj >= n) continue;

                if(currObs + grid[ni][nj] < obs[ni][nj]){
                    pq.push({currObs + grid[ni][nj], ni, nj});
                    obs[ni][nj] = currObs + grid[ni][nj];
                }
            }
        }

        return obs[m-1][n-1];
    }
};