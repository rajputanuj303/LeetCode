class Solution {
public:
    void dfs(string &s, unordered_map<string, int> &visited){

        if(visited[s] == 1) return;
        visited[s] = 1;
        
        for(int i = 0; i<s.size(); i++){
            for(int j = i+1; j<s.size(); j++){
                swap(s[i], s[j]);
                if(visited.count(s) && visited[s] == 0){
                    dfs(s, visited);
                }
                swap(s[i], s[j]);
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        unordered_map<string, int> visited;

        for(string &s : strs){
            visited[s] = 0;
        }

        int group = 0;

        for(string &s : strs){
            if(visited[s] == 0){
                group++;
                dfs(s, visited);
            }
        }

        return group;
    }
};