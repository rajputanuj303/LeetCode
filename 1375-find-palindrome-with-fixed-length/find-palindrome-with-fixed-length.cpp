class Solution {
public:
    long long makePal(long long firstHalf, bool odd) {
        string s = to_string(firstHalf);
        string rev = s;

        if (odd)
            rev.pop_back();      // don't duplicate middle digit

        reverse(rev.begin(), rev.end());

        return stoll(s + rev);
    }

    vector<long long> kthPalindrome(vector<int>& queries, int len) {

        int half = (len + 1) / 2;

        long long start = pow(10LL, half - 1);
        long long limit = start * 9;

        vector<long long> ans;

        for (int q : queries) {

            if (q > limit) {
                ans.push_back(-1);
                continue;
            }

            long long firstHalf = start + q - 1;

            ans.push_back(makePal(firstHalf, len & 1));
        }

        return ans;
    }
};