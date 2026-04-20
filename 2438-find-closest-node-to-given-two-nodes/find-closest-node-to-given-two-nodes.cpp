class Solution {
public:
    void dfs(int u, int dis, vector<int> &dist, vector<int> &edges){

        dist[u] = dis;

        if(edges[u] != -1 && dist[edges[u]] == INT_MAX){
            dfs(edges[u], dis+1, dist, edges);
        }

    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);

        dfs(node1, 0, dist1, edges);
        dfs(node2, 0, dist2, edges);

        int minIdx = -1;

        int minVal = 1e9+7;

        for(int i = 0; i<n; i++){
            if(max(dist1[i], dist2[i]) < minVal){
                minVal = max(dist1[i], dist2[i]);
                minIdx = i;
            }
        }

        return minIdx;
    }
};