class Solution {
public:
    vector<int> parent;
    int find(int u){
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    void Union(int u, int v){
        
        int pu = find(u);
        int pv = find(v);

        if(pu != pv){
            parent[pv] = pu;
        }
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        for(int i = 0; i<n; i++) parent.push_back(i);

        for(int i = 1; i<n; i++){
            if(nums[i]-nums[i-1] <= maxDiff){
                Union(i, i-1);
            }
        }

        vector<bool> res;

        for(vector<int> &q : queries){
            
            int pu = find(q[0]);
            int pv = find(q[1]);

            if(pu == pv) res.push_back(true);
            else res.push_back(false);
        }

        return res;
    }
};