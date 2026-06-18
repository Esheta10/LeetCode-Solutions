class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        // angle in 1 min = 360/60
        double minute_angle = 6.0 * minutes; 
        // angle in 1 hr  = 360/12 = 30
        // distance covered by minute angle = 360/720 = 0.5
        double hour_angle = 30.0 * (hour % 12) + 0.5 * minutes;

        double difference = abs(hour_angle - minute_angle);

        return min(difference, 360.0 - difference);
    }
};