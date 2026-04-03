class Solution {
public:
    void DFS(int u, int &n, vector<int> currPath, vector<vector<int>> &AllPaths, vector<vector<int>> &graph){

        currPath.push_back(u);

        if(u == n-1){
            if(currPath.size()){
                AllPaths.push_back(currPath);
            }
            return;
        }       

        for(int v : graph[u]){
            DFS(v, n, currPath, AllPaths, graph);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> AllPaths;
        vector<int> currPath;

        int n = graph.size();

        DFS(0, n, currPath, AllPaths, graph);

        return AllPaths;
    }
};