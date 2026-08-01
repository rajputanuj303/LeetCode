class Solution {
public:
    pair<int, int> Solver(int i, int j, int chance, vector<int> &nums){
        if(i > j) return {0, 0};

        if(chance == 1){

            pair<int, int> pair1 = Solver(i+1, j, 2, nums);
            pair<int, int> pair2 = Solver(i, j-1, 2, nums);

            if(nums[i] + pair1.first >= nums[j] + pair2.first){
                return {nums[i] + pair1.first, pair1.second};
            }else{
                return {nums[j] + pair2.first, pair2.second};
            }            
        }else{

            pair<int, int> pair1 = Solver(i+1, j, 1, nums);
            pair<int, int> pair2 = Solver(i, j-1, 1, nums);

            if(nums[i] + pair1.second >= nums[j] + pair2.second){
                return {pair1.first, nums[i] + pair1.second};
            }else{
                return {pair2.first, nums[j] + pair2.second};
            } 
        }

    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        pair<int, int> res = Solver(0, n-1, 1, nums);
        if(res.first >= res.second) return true;
        return false;
    }
};