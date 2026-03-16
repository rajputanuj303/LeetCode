class Solution {
public:

    int n;

    int Solver(int mul, vector<int> &nums, vector<map<vector<int>, int>> &mpp){

        if(mpp[mul].find(nums) != mpp[mul].end()) return mpp[mul][nums];

        int res = 0;

        for(int i = 0; i<n; i++){
            if(nums[i] == 0) continue;

            int v1 = nums[i];
            nums[i] = 0;

            for(int j = i+1; j<n; j++){
                if(nums[j] == 0) continue;

                int v2 = nums[j];
                nums[j] = 0;

                res = max(res, mul * gcd(v1, v2) + Solver(mul+1, nums, mpp));

                nums[j] = v2;
            }

            nums[i] = v1;
        }

        return mpp[mul][nums] = res;
    }

    int maxScore(vector<int>& nums) {

        n = nums.size();

        vector<map<vector<int>, int>> mpp(n+2);
        return Solver(1, nums, mpp);
    }
};