class Solution {
public:
    vector<int> parent, sz;

    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    void Union(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return;

        // Attach smaller tree under larger tree
        if (sz[pu] < sz[pv]) swap(pu, pv);

        parent[pv] = pu;
        sz[pu] += sz[pv];
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++) parent[i] = i;

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff) Union(i, i - 1);
        }

        vector<bool> ans;
        for (auto &q : queries) ans.push_back(find(q[0]) == find(q[1]));

        return ans;
    }
};