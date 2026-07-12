class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        

        vector<int> Edges(n, 0);

        vector<vector<bool>> present(n, vector<bool>(n, false));

        for(int i = 0; i<roads.size(); i++){
            Edges[roads[i][0]]++;
            Edges[roads[i][1]]++;

            present[roads[i][0]][roads[i][1]] = 1;
            present[roads[i][1]][roads[i][0]] = 1;
        }


        int result = 0;

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                // cout << Edges[i] << " " << Edges[j] << " " << present[i][j] << endl; 
                result = max(result, Edges[i] + Edges[j] - (present[i][j]));
            }
        }

        return result;
    }
};