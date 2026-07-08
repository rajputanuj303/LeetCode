class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        
        int n = s.size();
        int MOD = 1e9 + 7;

        vector<int> prefixNonZero(n);
        vector<int> prefixSum(n);
        vector<int> prefixNonZeroLength(n);
        vector<int> pow10(n + 1);

        pow10[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow10[i] = (1LL * pow10[i - 1] * 10) % MOD;
        }

        int digit = s[0] - '0';
        prefixNonZero[0] = digit;
        prefixSum[0] = digit % MOD;
        prefixNonZeroLength[0] = (digit != 0);

        for (int i = 1; i < n; i++) {
            digit = s[i] - '0';

            if (digit == 0) {
                prefixNonZero[i] = prefixNonZero[i - 1];
                prefixNonZeroLength[i] = prefixNonZeroLength[i - 1];
            } 
            else {
                prefixNonZero[i] = ( (1LL * prefixNonZero[i - 1] * 10) % MOD + digit ) % MOD;
                prefixNonZeroLength[i] = prefixNonZeroLength[i - 1] + 1;
            }

            prefixSum[i] = (prefixSum[i - 1] + digit) % MOD;
        }

        vector<int> output;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            int leftVal = (l == 0 ? 0 : prefixNonZero[l - 1]);
            int rightVal = prefixNonZero[r];

            int diff = prefixNonZeroLength[r] - 
                       (l == 0 ? 0 : prefixNonZeroLength[l - 1]);

            int val = (rightVal - (1LL * leftVal * pow10[diff]) % MOD + MOD) % MOD;

            int sum = (prefixSum[r] - (l == 0 ? 0 : prefixSum[l - 1]) + MOD) % MOD;

            int res = (1LL * val * sum) % MOD;

            output.push_back(res);
        }

        return output;
    }
};