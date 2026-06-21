class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        
        vector<vector<pair<int, int>>> adjLs(n);

        vector<vector<int>> minDis(
            n, vector<int>(k + 1, INT_MAX)
        );

        for(vector<int> &vec : edges){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            // Directed Graph
            adjLs[u].push_back({v, w}); 
        } 

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // {wt, node, k}
        pq.push({0, 0, k});
        minDis[0][k] = 0;

        while(!pq.empty()){
            vector<int> curr = pq.top();
            pq.pop();

            int currW = curr[0];
            int currU = curr[1];
            int currK = curr[2];

            for(pair<int, int> &neigh : adjLs[currU]){
                int nextV = neigh.first;
                int nextW = neigh.second;

                int newK = currK;

                if(labels[currU] == labels[nextV]) newK--;
                else newK = k;

                if(newK == 0) continue;


                if(currW + nextW < minDis[nextV][newK]){

                    minDis[nextV][newK] = currW + nextW;
                    pq.push({currW+nextW, nextV, newK});
                }

            }
        }
        
        int ans = INT_MAX;

        for(int rem = 0; rem <= k; rem++)
            ans = min(ans, minDis[n - 1][rem]);
        
        return (ans == INT_MAX) ? -1 : ans;

    }
};