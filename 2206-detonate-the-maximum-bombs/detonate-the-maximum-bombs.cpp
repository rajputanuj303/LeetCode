class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {

        int n = bombs.size();
        vector<vector<int>> adj(n);

        // Build graph
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                long long dx = 1LL * bombs[j][0] - bombs[i][0];
                long long dy = 1LL * bombs[j][1] - bombs[i][1];
                long long distSq = dx * dx + dy * dy;

                if (distSq <= 1LL * bombs[i][2] * bombs[i][2])
                    adj[i].push_back(j);

                if (distSq <= 1LL * bombs[j][2] * bombs[j][2])
                    adj[j].push_back(i);
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {

            vector<bool> vis(n, false);
            queue<int> q;

            q.push(i);
            vis[i] = true;

            int cnt = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                cnt++;

                for (int v : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }

            ans = max(ans, cnt);

            if (ans == n)
                return n;
        }

        return ans;
    }
};