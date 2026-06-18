class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double minAngle = minutes*6;
        double hrsAngle = (hour*30)%360 + minutes*0.5;

        return min(abs(hrsAngle - minAngle), (360 - abs(minAngle - hrsAngle)));

    }
};