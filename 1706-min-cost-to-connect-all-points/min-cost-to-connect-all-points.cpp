class Solution {
public:
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<vector<pair<int, int>>> adjLs(V);
        for(int i = 0; i<V; i++){
            for(int j = i+1; j<V; j++){
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adjLs[i].push_back({j, dis});
                adjLs[j].push_back({i, dis});
            }
        }
        // {wt, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // min-heap
        
        pq.push({0, 0});  
        vector<bool> visited(V, 0);

        int minCost = 0;

        while(!pq.empty()){
            
            pair<int, int> curr = pq.top();
            pq.pop();

            if(visited[curr.second]) continue;
            
            minCost += curr.first;
            visited[curr.second] = 1;

            for(pair<int, int> &p : adjLs[curr.second]){
                if(!visited[p.first]){
                    pq.push({p.second, p.first});
                }
            }            
        }

        return minCost;

    }
};