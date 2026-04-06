class Solution {
public:
    bool canReach(vector<int>& arr, int start) {

        int n = arr.size();

        queue<int> que;
        que.push(start);

        vector<int> visited(n, false);

        while(!que.empty()){
            int curr_idx = que.front();
            if(arr[curr_idx] == 0) return true;
            visited[curr_idx] = true;
            que.pop();

            if(curr_idx + arr[curr_idx] < n && !visited[curr_idx + arr[curr_idx]]){
                que.push(curr_idx + arr[curr_idx]);
            } 
                    
            if(curr_idx - arr[curr_idx] >= 0 && !visited[curr_idx - arr[curr_idx]]){
                que.push(curr_idx - arr[curr_idx]);
            }
        }

        return false;
    }
};