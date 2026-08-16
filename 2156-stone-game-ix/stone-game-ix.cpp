class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;

        for (int i : stones) {
            if (i % 3 == 0) cnt0++;
            else if (i % 3 == 1) cnt1++;
            else cnt2++;
        }

        if (cnt0 % 2 == 0) {
            return cnt1 > 0 && cnt2 > 0;
        }

        return abs(cnt1 - cnt2) > 2;
    }
};