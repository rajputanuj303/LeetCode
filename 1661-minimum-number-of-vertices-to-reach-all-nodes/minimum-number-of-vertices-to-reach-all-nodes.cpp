class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int> inComing(n, 0);

        for(vector<int> &edge : edges){
            int u = edge[0];
            int v = edge[1];

            inComing[v]++;
        }

        vector<int> res;

        for(int i = 0; i<n; i++){
            if(inComing[i] == 0) res.push_back(i);
        }

        return res;
    }
};