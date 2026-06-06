class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int leftSum = 0, TotalSum = 0;
        vector<int> answer;
        for(int &i : nums) TotalSum += i;
        
        for(int i = 0; i<nums.size(); i++){
            answer.push_back(abs(leftSum - TotalSum + leftSum + nums[i]));
            leftSum += nums[i];
        }
        return answer;
    }
};