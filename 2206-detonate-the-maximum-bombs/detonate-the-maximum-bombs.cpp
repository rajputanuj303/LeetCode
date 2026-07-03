class Solution {
public:

    int dfs(int u, vector<vector<int>> &adjLs, vector<bool> &visited){

        visited[u] = true;

        int res = 1;

        for(int v : adjLs[u]){
            if(!visited[v]){
                res += dfs(v, adjLs, visited);
            }
        }

        return res;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n = bombs.size();

        vector<vector<int>> adjLs(n);

        for(int i = 0; i<n; i++){

            vector<int> x = bombs[i];

            for(int j = i+1; j<n; j++){

                vector<int> y = bombs[j];

                long long dx = 1LL * bombs[j][0] - bombs[i][0];
                long long dy = 1LL * bombs[j][1] - bombs[i][1];
                long long distSq = dx * dx + dy * dy;

                if(distSq <= 1LL*x[2]*x[2]) adjLs[i].push_back(j);
                if(distSq <= 1LL*y[2]*y[2]) adjLs[j].push_back(i);
            }
        }

        int res = 0;
        
        for(int i = 0; i<n; i++){
            vector<bool> visited(n, false);
            res = max(res, dfs(i, adjLs, visited));
        }

        return res;
    }
};