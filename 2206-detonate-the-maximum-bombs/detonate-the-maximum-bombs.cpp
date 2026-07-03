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

                long long square = pow((y[0]*1LL-x[0]), 2) + pow((y[1]*1LL-x[1]), 2);
                double dist = sqrt(square);

                if(dist <= x[2]) adjLs[i].push_back(j);
                if(dist <= y[2]) adjLs[j].push_back(i);
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