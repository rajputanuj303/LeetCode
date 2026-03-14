class Solution {
public:
    
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        int maxi = nums[0];

        vector<long long> gcds(n);
        gcds[0] = maxi;

        for(int i = 1; i<n; i++){
            maxi = max(maxi, nums[i]);
            gcds[i] = gcd(maxi, nums[i]);
        }

        sort(gcds.begin(), gcds.end());

        long long sum = 0;
        int i = 0, j = n-1;

        while(i < j){
            sum += gcd(gcds[i++], gcds[j--]);
        }
        return sum;
    }
};