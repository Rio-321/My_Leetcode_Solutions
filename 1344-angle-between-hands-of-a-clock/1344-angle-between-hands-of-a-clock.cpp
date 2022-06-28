class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        // 1 minute = 6 degree
        
        double hourDegree = (hour%12)*30 + ((minutes)/2.00);
        double minuteDegree = minutes * 6;
        
        double diff = abs(hourDegree - minuteDegree);
        
        return min(diff, 360-diff);
    }
};