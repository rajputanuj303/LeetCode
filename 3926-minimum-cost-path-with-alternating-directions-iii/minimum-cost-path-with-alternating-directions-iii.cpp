class Solution {
public:
    using ll = long long;

    class box {
    public:
        ll cost;
        int parity;
        int i;
        int j;

        box(ll c, int p, int I, int J){
            cost = c;
            parity = p;
            i = I;
            j = J;
        }
            
    };

    struct cmp {
        bool operator()(box &a, box &b) {
            return a.cost > b.cost;   // min-heap
        }
    };

    long long minCost(int m, int n, vector<vector<int>>& penalty) {

        vector<vector<vector<ll>>> dist(
            m, vector<vector<ll>>(n, vector<ll>(2, LLONG_MAX)));

        priority_queue<box, vector<box>, cmp> pq;

        pq.push(box(1, 0, 0, 0));
        dist[0][0][0] = 1;

        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};

        while (!pq.empty()) {

            box cur = pq.top();
            pq.pop();

            ll cost = cur.cost;
            int parity = cur.parity;
            int i = cur.i;
            int j = cur.j;

            // Ignore outdated state
            if (cost != dist[i][j][parity])
                continue;

            int newParity = parity ^ 1;

            // Wait
            ll waitCost = cost + penalty[i][j];
            if (waitCost < dist[i][j][newParity]) {
                dist[i][j][newParity] = waitCost;
                pq.push(box(waitCost, newParity, i, j));
            }

            // Move
            for (int k = 0; k < 4; k++) {

                int ni = i + dr[k];
                int nj = j + dc[k];

                if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                    continue;

                ll newCost = cost + 1LL * (ni + 1) * (nj + 1);

                // Invalid move => pay waiting penalty
                if ((newParity == 1 && (dr[k] + dc[k] == -1)) ||
                    (newParity == 0 && (dr[k] + dc[k] == 1))) {
                    newCost += penalty[i][j];
                }

                if (newCost < dist[ni][nj][newParity]) {
                    dist[ni][nj][newParity] = newCost;
                    pq.push(box(newCost, newParity, ni, nj));
                }
            }
        }

        return min(dist[m - 1][n - 1][0], dist[m - 1][n - 1][1]);
    }
};