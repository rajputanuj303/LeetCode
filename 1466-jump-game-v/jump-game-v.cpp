class Solution {
public:
    int dfs(int i, int &n, vector<int> &arr, int d, vector<int> &visited){
        if(visited[i] != -1) return visited[i];

        int mini = max(0, i - d); 
        int maxi = min(n-1, i + d); 

        int steps = 1;

        for(int j = i-1; j>=mini; j--){
            if(arr[j] >= arr[i]) break;
            steps = max(steps, 1 + dfs(j, n, arr, d, visited));
        }
        for(int j = i+1; j<=maxi; j++){
            if(arr[j] >= arr[i]) break;
            steps = max(steps, 1 + dfs(j, n, arr, d, visited));
        }
        

        return visited[i] = steps;
    }

    int maxJumps(vector<int>& arr, int d) {
        
        int n = arr.size();
        vector<int> visited(n+1, -1);

        int steps = 0;

        for(int i = 0; i<n; i++){
            steps = max(steps, dfs(i, n, arr, d, visited));
        }

        return steps;
    }
};