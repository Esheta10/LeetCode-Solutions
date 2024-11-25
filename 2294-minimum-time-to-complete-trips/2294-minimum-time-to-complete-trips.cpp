class Solution {
public:
    bool possible(vector<int>& time,long long given_time, int totalTrips)
    {
        long long actual_trips = 0;
        for(int &t:time)
        {
            actual_trips += given_time/t;
        }
        return actual_trips >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
    int n = time.size();
    long long l = 1;
    long long r= (long long) *min_element(time.begin(),time.end())*totalTrips;
    
        while(l < r)
        {
            long long mid_time = l+(r-l)/2;

            if(possible(time,mid_time,totalTrips))
                r = mid_time;
            else
                l = mid_time + 1;
        }
        return l;
    }
};