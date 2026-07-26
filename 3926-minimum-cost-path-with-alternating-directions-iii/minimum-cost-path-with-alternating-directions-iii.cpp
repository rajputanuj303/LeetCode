class Solution {
public:
    using ll = long long;
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        

        // stores minimum cost at (i, j) on both parities.
        vector<vector<vector<ll>>> dist(m, vector<vector<ll>>(n, vector<ll>(2, LLONG_MAX)));

        // stores {cost, parity, i, j} and returns minium cost in pq.
        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;

        //starting point
        pq.push({1, 0, 0, 0});  
        dist[0][0][0] = 1;

        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};

        while(!pq.empty()){

            auto v = pq.top();
            pq.pop();

            ll c = v[0], p = v[1], i = v[2], j = v[3];
            
            // new parity.
            ll newParity = p ^ 1;

            // Wait
            if(c + penalty[i][j] < dist[i][j][newParity]){
                pq.push({c + penalty[i][j], newParity, i, j});
                dist[i][j][newParity] = c + penalty[i][j];
            }

            // Move
            for(int k = 0; k<4; k++){

                int ni = i + dr[k];
                int nj = j + dc[k];

                if(ni >= 0 && nj >= 0 && ni < m && nj < n){ // valid cell.

                    ll newCost = c + (1LL * (ni + 1) * (nj + 1)); // adds everytime.

                    // violation condition.                    
                    if((newParity == 1) && (dr[k] + dc[k] == -1)) { // odd and (left, up)
                        newCost += penalty[i][j];                        
                    }else if((newParity == 0) && (dr[k] + dc[k] == 1)) { // even and (right, down)
                        newCost += penalty[i][j];
                    }

                    if(newCost < dist[ni][nj][newParity]){
                        pq.push({newCost, newParity, ni, nj});
                        dist[ni][nj][newParity] = newCost;
                    }
                }
            }
        }
        return min(dist[m-1][n-1][0], dist[m-1][n-1][1]);
    }
};