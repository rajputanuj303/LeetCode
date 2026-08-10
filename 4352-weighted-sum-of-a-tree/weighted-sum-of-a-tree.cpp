class Solution {
public:

    long long dfs(int u, vector<vector<int>> &adjLs){

        long long maxHeight = 1;
        for(int v : adjLs[u]){
            maxHeight = max(maxHeight, 1 + dfs(v, adjLs));
        }

        return maxHeight;
    }
    
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> adjLs(n);

        for(int i = 0; i<n; i++){
            if(parent[i] == -1) continue;
            adjLs[parent[i]].push_back(i);
        }

        queue<int> que;
        que.push(0);

        long long height = dfs(0, adjLs);
        long long depth = 1;
        long long res = 0;

        while(!que.empty()){
            int s = que.size();

            while(s--){
                int curr = que.front();
                que.pop();              

                long long weight = 1LL*(nums[curr]*(height - depth + 1));
                res += weight;                
                for(int v : adjLs[curr]){
                    que.push(v);
                }
            }
            depth++;
        }
        return res;
    }
};