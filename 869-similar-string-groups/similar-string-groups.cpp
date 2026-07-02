class Solution {
public:

    bool isSimilar(string &s1, string &s2){
        int diff = 0;

        for(int i = 0; i < s1.size(); i++){
            if(s1[i]  != s2[i]) diff++;
            if(diff > 2) return false;
        }

        return true;
    }

    void dfs(int u, vector<bool> &visited, vector<vector<int>> &adjLs){
        visited[u] = 1;

        for(int v : adjLs[u]){
            if(!visited[v]) dfs(v, visited, adjLs);
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        

        int N = strs.size();

        vector<vector<int>> adjLs(N);

        for(int i = 0; i<N; i++){
            for(int j = i+1; j<N; j++){
                if(isSimilar(strs[i], strs[j])){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        int groups = 0;

        vector<bool> visited(N, 0);

        for(int i = 0; i<N; i++){
            if(visited[i] == 0){
                groups++;
                dfs(i, visited, adjLs);
            }
        }

        return groups;
    }
};