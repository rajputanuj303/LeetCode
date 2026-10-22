class Solution {
public:

    bool isIncreasingCycle(vector<int> &nums, int &n, int &pos){
        for(int i = 1; i < n; i++){
            if(nums[(pos + i)%n] != i) return false;
        }
        return true;
    }

    bool isDecreasingCycle(vector<int> &nums, int &n, int &pos){
        for(int i = 1; i<n; i++){
            if(nums[(pos - i + n)%n] != i) return false;
        }
        return true;
    }
    
    int minOperations(vector<int>& nums) {

        int n = nums.size();
        int pos = -1;

        for(int i = 0; i<n; i++){
            if(nums[i] == 0) {
                pos = i;
                break;
            }      
        }

        int mini = 1e9+7;

        if(isIncreasingCycle(nums, n, pos)) mini = min({mini, pos, n - pos + 2});
        if(isDecreasingCycle(nums, n, pos)) mini = min({mini, pos + 2, n - pos});

        return mini == 1e9+7 ? -1 : mini;        
    }
};