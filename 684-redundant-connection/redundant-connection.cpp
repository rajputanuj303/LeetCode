class Solution {
public:
    vector<int> parent;

    int find(int u){
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]); 
    }

    void Union(int u, int v){

        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return;
        parent[pv] = pu;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();

        parent.resize(n+1);

        for(int i = 1; i<=n; i++) parent[i] = i;


        for(vector<int> &edge : edges){
            int u = edge[0];
            int v = edge[1];

            if(find(u) == find(v)){
                return {u, v};
            }
            Union(u, v);
        }
        return {-1, -1};
    }
};