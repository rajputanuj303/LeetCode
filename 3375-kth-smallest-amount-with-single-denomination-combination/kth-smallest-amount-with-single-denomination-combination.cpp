class Solution {
public:
    int n;
    long long UniqueEleLessThanVal(long long &val, vector<int> &coins){

        long long totalCount = 0;

        for(int i = 0; i<n; i++){
            totalCount += (val / coins[i]);
        }

        // Inclusion-Exclusion
        for (int mask = 1; mask < (1 << n); mask++) {

            int countBits = __builtin_popcount(mask);
            if(countBits <= 1) continue;

            long long LCM = 1;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {

                    long long GCD = gcd(LCM, (long long)coins[i]);

                    // Avoid overflow
                    LCM = (LCM / GCD) * coins[i];
                    if (LCM > val) break;
                }
            }

            if (LCM > val) continue;

            if (countBits % 2 == 0) totalCount -= val / LCM;
            else totalCount += val / LCM;
        }
        return totalCount;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        
        n = coins.size();

        int maxElement = *max_element(coins.begin(), coins.end());

        long long left = 0, right = 1LL*maxElement*k + 1;
        long long result = -1;

        // Binary Search on Answer
        while(left <= right){
            long long mid = left + (right - left)/2;
            
            // number of unique element less than mid.
            long long count = UniqueEleLessThanVal(mid, coins);
            
            if(count >= k){
                result = mid;
                right = mid-1;
            }else{
                left = mid+1;
            } 
        }

        return result;
    }
};