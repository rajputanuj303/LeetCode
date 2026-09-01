class Solution {
public:
    void Solver(vector<int> &nums, unordered_set<int> &stt, vector<int> &temp, vector<vector<int>> &result){

        if(stt.size() == n){
            result.push_back(temp);
            return;
        }


        for(int i = 0; i<n; i++){
            // check whther already used or not
            if(stt.count(i)) continue;

            // not used;

            stt.insert(i);
            temp.push_back(nums[i]);

            Solver(nums, stt, temp, result);

            stt.erase(i);
            temp.pop_back();
        }
    }
    int n;
    vector<vector<int>> permute(vector<int>& nums) {
        
        n = nums.size();

        unordered_set<int> used; // set to track indexes
        vector<vector<int>> result; // 2D result
        vector<int> temp;
        Solver(nums, used, temp, result);
        
        return result;
    }
};