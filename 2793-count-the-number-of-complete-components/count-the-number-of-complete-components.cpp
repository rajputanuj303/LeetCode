class Solution {
public:
    vector<int> parent;

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int u, int v){

        int pu = find(u);
        int pv = find(v);
        
        if(pu != pv){
            parent[pv] = pu;
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        for(int i = 0; i<n; i++) parent.push_back(i);

        set<pair<int, int>> stt;

        for(vector<int> vec : edges){
            int u = vec[0];
            int v = vec[1];

            if(u > v) swap(u, v);    
            Union(u, v);
            stt.insert({u, v});
        }

        unordered_map<int, vector<int>> mpp;

        for(int i = 0; i<n; i++){
            mpp[find(i)].push_back(i);
        }

        int cnt = 0;

        for(auto p : mpp){

            vector<int> arr = p.second;
            int N = arr.size();
            bool flag = true;

            for(int i = 0; i<N; i++){
                for(int j = i+1; j<N; j++){
                    int u = arr[i];
                    int v = arr[j];

                    if(stt.find({u, v}) == stt.end()){
                        flag = false;
                        goto Break;
                    }
                }
            }

            Break:
            if(flag) cnt++;
        }
        
        return cnt;
    }
};