class Solution {
public:
    void DFS(int u, int &n, vector<int> &currPath, vector<vector<int>> &AllPaths, vector<vector<int>> &graph){

        if(u == n-1){
            currPath.push_back(u);
            AllPaths.push_back(currPath);
            currPath.pop_back();
            return;
        }       

        for(int v : graph[u]){
            currPath.push_back(u);
            DFS(v, n, currPath, AllPaths, graph);
            currPath.pop_back();
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