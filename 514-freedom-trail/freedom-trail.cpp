class Solution {
public:
    unordered_map<char, vector<int>> mpp;
    vector<vector<int>> visited;

    int n, k;

    int Solver(int i, int start, string str){

        if(i >= k) return 0;
        if(visited[start][i] != -1) return visited[start][i];

        char c = str[i];
        int minDis = INT_MAX;

        for(int idx : mpp[c]){            
            int diff = abs(idx - start);
            diff =  min(diff, n - diff);
            minDis = min(minDis, 1 + diff + Solver(i+1, idx, str));
        }

        return visited[start][i] = minDis;
    }

    int findRotateSteps(string ring, string key) {

        n = ring.size();
        k = key.size();

        visited.assign(n, vector<int>(k, -1));

        for(int i = 0; i<n; i++){
            mpp[ring[i]].push_back(i);
        }
        return Solver(0, 0, key);
    }
};