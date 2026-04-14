class Solution {
public:
    pair<bool, int> dfs(int u, vector<vector<int>> &adjLs, vector<bool> &hasApple, vector<bool> &visited){
        
        visited[u] = true;

        bool foundApple = hasApple[u];
        int time = 0;

        for(int &v : adjLs[u]){

            if(!visited[v]){
                
                pair<bool, int> neigh = dfs(v, adjLs, hasApple, visited);
                
                if(neigh.first){
                    time += neigh.second + 2; 
                    foundApple = true;
                }
            }
        }

        return {foundApple, time};
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adjLs(n);

        for(vector<int> &v : edges){
            adjLs[v[0]].push_back(v[1]);
            adjLs[v[1]].push_back(v[0]);
        }

        vector<bool> visited(n, false);

        pair<bool, int> res = dfs(0, adjLs, hasApple, visited);

        return res.second;
    }
};