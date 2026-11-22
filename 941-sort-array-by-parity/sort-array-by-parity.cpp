class Solution {
public:
    bool iseven(int a){
        return (a % 2 == 0);
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0 , j = nums.size() - 1;

        while ( i < j){
            if (iseven(nums[i]) and iseven(nums[j])){
                i++;
            }else if (iseven(nums[i])==false and iseven(nums[j]) == false){
                j--;
            }else if (iseven(nums[i]) == true and iseven(nums[j])==false){
                j--;
                i++;
            }else{
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        return nums;
    }
};