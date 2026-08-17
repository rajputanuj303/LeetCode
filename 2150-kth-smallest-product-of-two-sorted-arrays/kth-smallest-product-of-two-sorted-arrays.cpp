class Solution {
public:
    using ll = long long;

    ll countSmallerProd(ll product, vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        ll count = 0;

        for (ll num1 : nums1) {

            if (num1 >= 0) {
                // Find the last index where:
                // num1 * nums2[i] <= product

                int left = 0, right = n - 1;
                int res = -1;

                while (left <= right) {
                    int mid = left + (right - left) / 2;

                    ll currProd = num1 * 1LL * nums2[mid];

                    if (currProd <= product) {
                        res = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }

                count += res + 1;
            }

            else {
                // Find the first index where:
                // num1 * nums2[i] <= product

                int left = 0, right = n - 1;
                int res = n;

                while (left <= right) {
                    int mid = left + (right - left) / 2;

                    ll currProd = num1 * 1LL * nums2[mid];

                    if (currProd <= product) {
                        res = mid;
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }

                count += (n - res);
            }
        }

        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {

        ll left = -1e10;
        ll right = 1e10;

        while (left < right) {

            ll mid = left + (right - left) / 2;

            ll count = countSmallerProd(mid, nums1, nums2);

            if (count >= k) {
                // mid can be the answer
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};