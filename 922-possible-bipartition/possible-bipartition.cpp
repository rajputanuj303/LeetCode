class Solution {
public:

    //-1 --> N/A, 0 --> R, 1 --> G

    bool dfs(int i, int col, vector<int> &visited, vector<vector<int>> &adjLs){
        
        visited[i] = col;

        for(const int &ele : adjLs[i]){
            if(visited[ele] == -1){
                if(!dfs(ele, 1 - col, visited, adjLs)) return false;
            }else if(visited[ele] == col) return false;
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<vector<int>> adjLs(n+1);

        for(const vector<int> &v : dislikes){
            adjLs[v[0]].push_back(v[1]);
            adjLs[v[1]].push_back(v[0]);
        }

        vector<int> visited(n+1, -1);

        for(int i = 1; i <= n; i++){
            if(visited[i] == -1){
                if(!dfs(i, 0, visited, adjLs)) return false;
            }
        }

        return true;
    }
};