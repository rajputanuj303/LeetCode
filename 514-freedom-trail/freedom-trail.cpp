class Solution {
public:
    unordered_map<char, vector<int>> mpp;
    unordered_map<string, int> visited;

    int n;

    int Solver(int i, int start, string str){
        if(i >= str.size()) return 0;

        string key = to_string(i) + "#" + to_string(start);

        if(visited.count(key)) return visited[key];

        char c = str[i];

        int minDis = INT_MAX;

        for(int idx : mpp[c]){
            
            int diff = abs(idx - start);
            diff =  min(diff, n - diff);

            minDis = min(minDis, 1 + diff + Solver(i+1, idx, str));
        }
        return visited[key] = minDis;
    }

    int findRotateSteps(string ring, string key) {

        n = ring.size();

        for(int i = 0; i<ring.size(); i++){
            mpp[ring[i]].push_back(i);
        }
        return Solver(0, 0, key);
    }
};