class Solution {
public:
    bool canAliceWin(int n) {
        bool t = 0;
        int pile = 10;

        while (n >= pile) {
            n -= pile--;
            t ^= 1;
        }

        return t;
    }
};