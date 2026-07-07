class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> adjLs;

    double dfs(string src, string des, unordered_set<string> &visited){

        if(visited.count(src)) return -1.0;
        if(src == des) return 1.0;

        visited.insert(src);

        for(pair<string, double> &p : adjLs[src]){

            double ans = dfs(p.first, des, visited);
            
            if(ans != -1.0){
                visited.erase(src);
                return p.second * ans;
            }
        }

        visited.erase(src);

        return -1.0;
    }


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        int n = equations.size();

        for(int i = 0; i<n; i++){
            string u = equations[i][0];
            string v = equations[i][1];
            adjLs[u].push_back({v, values[i]});
            adjLs[v].push_back({u, 1.0/values[i]});
        }

        int q = queries.size();

        vector<double> output(q, -1.0);
        unordered_set<string> visited;

        for(int i = 0; i<q; i++){
            string src = queries[i][0];
            string des = queries[i][1];            
            if(adjLs.count(src) && adjLs.count(des)){
                output[i] = dfs(src, des, visited);
            }
        }        
        return output;
    }
};