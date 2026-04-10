class Solution {
public:
    void dfs(int st, int &n, vector<bool> & visited, vector<vector<int>> &arr){
        visited[st] = true;

        int curri = arr[st][0];
        int currj = arr[st][1];

        for(int i = 0; i<n; i++){
            if(!visited[i] && (curri == arr[i][0] || currj == arr[i][1])){
                dfs(i, n, visited, arr);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();

        vector<bool> visited(n, false);

        int count = 0;

        for(int st = 0; st<n; st++){
            if(!visited[st]){
                dfs(st, n, visited, stones);
                count++;
            }
        }

        return n - count;
    }
};