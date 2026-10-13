class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        int half = (n+1)/2;
        sort(nums.begin(), nums.end());
        int p1 = 0, p2 = n-1;
        long long sum = 0;
        while(p1<=p2){
            if(half){
                if(abs(nums[p2]) >= abs(nums[p1])){
                    sum += (nums[p2]*nums[p2]);
                    p2--;
                }else{
                    sum += (nums[p1]*nums[p1]);
                    p1++;
                }
                half--;
            }else{
                sum -= (nums[p2]*nums[p2]);
                p2--;
            }
        }
        return sum;
    }
};