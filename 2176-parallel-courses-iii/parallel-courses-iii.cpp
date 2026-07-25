class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (auto &e : relations) {
            adj[e[0] - 1].push_back(e[1] - 1);
            indegree[e[1] - 1]++;
        }

        queue<int> q;
        vector<int> dist = time;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int ans = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            ans = max(ans, dist[u]);

            for (int v : adj[u]) {
                dist[v] = max(dist[v], dist[u] + time[v]);

                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        return ans;
    }
};