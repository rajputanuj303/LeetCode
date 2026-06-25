class Solution {
public:
    int edgeScore(vector<int>& edges) {
        
        int n = edges.size();

        vector<long long> edgeScore(n, 0);

        for(int u = 0; u<n; u++){
            int v = edges[u];

            edgeScore[v] += u;
        }

        int maxIdx = 0;

        for(int i = 1; i<n; i++){
            if(edgeScore[i] > edgeScore[maxIdx]) maxIdx = i;
        }

        return maxIdx;        
    }
};