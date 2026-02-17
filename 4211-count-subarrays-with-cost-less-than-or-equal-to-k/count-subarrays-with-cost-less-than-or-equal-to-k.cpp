class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {

        multiset<long long> mset;

        long long count = 0;

        int n = nums.size();
        int l = 0, r = 0;

        while(r < n){

            mset.insert(nums[r]);

            long long maxi = *mset.rbegin();
            long long mini = *mset.begin();

            long long cost = (maxi-mini)*(r-l+1);

            while(cost > k){

                mset.erase(mset.find(nums[l]));
                l++;

                maxi = *mset.rbegin();
                mini = *mset.begin();

                cost = (maxi-mini)*(r-l+1);
            }

            count += (r-l+1);
            r++;
        }

        return count;
    }
};