class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long left = 0;

        long long right = (long long)(*min_element(time.begin(), time.end())) * totalTrips;

        while(left < right){

            long long mid = left + (right - left)/2;
            long long trips = 0;

            for(int t: time)
                trips += mid/t;

            if(trips >= totalTrips)
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
};