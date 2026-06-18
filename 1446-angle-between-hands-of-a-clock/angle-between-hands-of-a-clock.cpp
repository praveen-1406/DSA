class Solution {
public:
    double angleClock(int hour, int minutes) {
        // 12:00 0 degree
        double minAngle=minutes*(360/60);
        double hourAngle=hour*(360/12);
        if(hourAngle>=360) hourAngle-=360;
        hourAngle+=30.0*(minutes/60.0);
        double diff=abs(hourAngle-minAngle);
        return min(diff,360-diff);
    }
};