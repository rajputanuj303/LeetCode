class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<int> ans(queries.size());

        unordered_map<int, int> last_seen;
        ranges::sort(logs, [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        int max_ = *ranges::max_element(queries);
        //vector<int> turned_on(max_+1, 0);
        vector<int> prefix_sum(max_+10, 0);

         for(int i = 0; i < logs.size(); i++){
            int time = logs[i][1], server = logs[i][0];
            int l = time, r = min(max_, time + x);

            if(l > max_) continue;

            if(last_seen.contains(server)) l = max(l, last_seen[server] + 1);

            if(l <= r){
                prefix_sum[l]++;
                prefix_sum[r+1]--;
            }

            last_seen[server] = max(last_seen[server], r);
        }

        for(int i = 1; i <= max_; i++){
            prefix_sum[i] += prefix_sum[i-1];
        }

        for(int i = 0; i < queries.size(); i++){
            int r = queries[i], l = r - x;
            ans[i] = n - prefix_sum[r];
        }
        

        return ans;
    }
};