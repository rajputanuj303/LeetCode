class Solution {
public:
    int maxi = -1;
    void dfs(int i, vector<int> &edges, vector<bool> &visited, vector<int> &pathEle){
        if(edges[i] == -1) return;

        if(visited[i] != 0){
            int found = -1;
            for(int j = 0; j<pathEle.size(); j++){
                if(pathEle[j] == i){
                    found = j;
                    break;
                }
            }

            if(found == -1) return;
            int size = pathEle.size();
            maxi = max(maxi, size - found);
            return;
        }

        visited[i] = true;

        pathEle.push_back(i);

        dfs(edges[i], edges, visited, pathEle);

        pathEle.pop_back();
    }
    int longestCycle(vector<int>& edges) {
        
        int n = edges.size();

        vector<bool> visited(n, 0);

        for(int i = 0; i<n; i++){
            if(visited[i]) continue;
            vector<int> pathElements;
            dfs(i, edges, visited, pathElements);
        }

        return maxi;
    }
};