class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& suspicious) {
        suspicious[u] = true;

        for (int v : adj[u]) {
            if (!suspicious[v])
                dfs(v, adj, suspicious);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n), incoming(n);

        for (auto &e : invocations) {
            adj[e[0]].push_back(e[1]);
            incoming[e[1]].push_back(e[0]);
        }

        vector<bool> suspicious(n, false);
        dfs(k, adj, suspicious);

        // Check whether suspicious component can be removed
        for (int u = 0; u < n; u++) {

            if (!suspicious[u]) continue;

            for (int v : incoming[u]) {
                if (!suspicious[v]) {
                    vector<int> ans;
                    for (int i = 0; i < n; i++)
                        ans.push_back(i);
                    return ans;
                }
            }
        }

        // Return all non-suspicious methods
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};