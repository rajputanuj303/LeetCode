class Solution {
public:
    pair<int,int> Solver(int i, int j, int chance, vector<int>& nums) {
        if(i > j) return {0,0};

        if(chance == 1) {

            pair<int, int> left = Solver(i+1, j, 2, nums);
            pair<int, int> right = Solver(i, j-1, 2, nums);


            if(nums[i] + left.first >= nums[j] + right.first)
                return {nums[i] + left.first, left.second};
            else
                return {nums[j] + right.first, right.second};

        } else {

            pair<int, int> left = Solver(i+1, j, 1, nums);
            pair<int, int> right = Solver(i, j-1, 1, nums);

            // int diffLeft = (left.second + nums[i]) - left.first;
            // int diffRight = (right.second + nums[j]) - right.first;

            if(left.second + nums[i] >= right.second + nums[j])
                return {left.first, nums[i] + left.second};
            else
                return {right.first, nums[j] + right.second};
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        pair<int, int> res = Solver(0, n-1, 1, nums);
        return res.first >= res.second;
    }
};