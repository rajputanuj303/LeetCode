class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        vector<int> indegree(n, 0);

        for(vector<int> &v : roads){
            indegree[v[0]]++;
            indegree[v[1]]++;
        }

        priority_queue<pair<int, int>> pq;

        for(int i = 0; i<n; i++){
            pq.push({indegree[i], i});
        }


        int idx = n;

        while(!pq.empty()){
            pair<int, int> curr = pq.top();
            pq.pop();
            indegree[curr.second] = idx--;
        }

        long long total = 0;

        for(vector<int> &v : roads){
            total += (indegree[v[0]] + indegree[v[1]]);
        }
        return total;
    }
};