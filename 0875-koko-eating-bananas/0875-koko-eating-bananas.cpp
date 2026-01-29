class Solution {
public:
    long long calculateHours(vector<int>& piles, int h){

        long long hours = 0;

        for(int num: piles){
            hours += (num + h -1)/h;
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int result = r;

        while(l <= r){
            int mid = l+(r-l)/2;

            long long hoursNeeded = calculateHours(piles, mid);

            if(hoursNeeded <= h){
                result = mid; // potential answer
                r = mid - 1; // search further left
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
};