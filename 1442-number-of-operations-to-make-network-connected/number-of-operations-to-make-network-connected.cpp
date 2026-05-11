class Solution {
public:

    void dfs(int i, vector<vector<int>> &adjLs, vector<int> &visited){
        visited[i] = 1;

        for(int j : adjLs[i]){
            if(visited[j] == 0)
                dfs(j, adjLs, visited);
        }
    }

    vector<int> parent;

    int find(int x){
        if(parent[x] == x) return x;

        return parent[x] = find(parent[x]);
    }

    void Unite(int a, int b){

        int pa = find(a);
        int pb = find(b);

        if(pa == pb) return;

        parent[pb] = pa;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {

        vector<vector<int>> adjLs(n);

        for(vector<int> &v : connections){
            adjLs[v[0]].push_back(v[1]);
            adjLs[v[1]].push_back(v[0]);
        }

        vector<int> visited(n, 0);

        int components = 0;
        for(int i = 0; i<n; i++){
            if(visited[i] == 0){
                components++;
                dfs(i, adjLs, visited);
            }
        }


        for(int i = 0; i<n; i++){
            parent.push_back(i);
        }

        int count = 0;

        for(vector<int> &v : connections){
            int a = v[0];
            int b = v[1];

            int pa = find(a);
            int pb = find(b);

            if(pa == pb){ 

                count++;               

            }else{
                Unite(a, b);
            }
        }

        if(count >= components-1){
            return components-1;
        }
        return -1;
    }
};