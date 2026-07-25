class Solution {
public:
    vector<int> visited;
    int dfs(int u, vector<vector<int>> &adjLs, vector<int> &time){
        
        if(visited[u] != -1) return visited[u];

        int maxi = 0;

        for(int v : adjLs[u]){
            maxi = max(maxi, dfs(v, adjLs, time));
        }
        return visited[u] = maxi + time[u];
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<vector<int>> adjLs(n);
        vector<int> inDegree(n, 0);

        for(vector<int> &v : relations){
            adjLs[v[1]-1].push_back(v[0]-1);
            inDegree[v[0]-1]++;
        }

        int maxi = 0;        
        visited.resize(n, -1);

        for(int i = 0; i<n; i++){
            if(inDegree[i] == 0){
                maxi = max(maxi, dfs(i, adjLs, time));
            }
        }

        return maxi;
    }
};