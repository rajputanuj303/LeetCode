class Solution {
public:
    void Solver(int i, int &n, vector<int> &nums, vector<vector<int>> &output){
        if(i == n){
            output.push_back(nums);
            return;
        }

        for(int j = i; j<n; j++){
            swap(nums[i], nums[j]);
            Solver(i+1, n, nums, output);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> output;
        int n = nums.size();

        Solver(0, n, nums, output);
        return output;
    }
};