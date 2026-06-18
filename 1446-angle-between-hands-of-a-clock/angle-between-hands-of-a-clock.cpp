class Solution {
public:
    double angleClock(int hour, int minutes) {
        double val = abs(30 * hour - 5.5 * minutes);
        return min(val, 360-val);
    }
};