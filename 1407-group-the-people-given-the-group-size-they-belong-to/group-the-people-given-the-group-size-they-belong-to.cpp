class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        int n = groupSizes.size();
        unordered_map<int, vector<int>> mpp; 
        vector<vector<int>> res;

        for(int i = 0; i<n; i++){

            int size = groupSizes[i];
            mpp[size].push_back(i);
            
            if(mpp[size].size() == size){
                res.push_back(mpp[size]);
                mpp[size].clear();
            }
            
        }       

        return res;
    }
};