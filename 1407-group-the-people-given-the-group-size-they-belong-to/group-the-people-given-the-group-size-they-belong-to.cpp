class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        unordered_map<int, vector<int>> mpp; 
        for(int i = 0; i<n; i++){
            mpp[groupSizes[i]].push_back(i);
        }


        vector<vector<int>> res;

        for(auto pair : mpp){
            int size = pair.first;
            vector<int> v = pair.second;

            vector<int> temp;
            for(int i = 0; i<v.size(); i++){
                temp.push_back(v[i]);
                if(temp.size() == size){
                    res.push_back(temp);
                    temp.clear();
                }
            }
        }

        return res;
    }
};