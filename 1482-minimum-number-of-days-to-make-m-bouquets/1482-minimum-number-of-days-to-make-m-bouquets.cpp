class Solution {
public:
    long long countBouquets(vector<int> bloomDay, int day, int k){

        int bouquets = 0;
        int consecutive = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                consecutive++;
                if(consecutive==k){ 
                    bouquets++;
                    consecutive = 0;
                }
            } else {
                consecutive = 0; // break on non-bloomed rose;
            }
        }
        return bouquets;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // m = bouquets
        // k = roses
        int n = bloomDay.size();
        long long totalRosesNeeded = (long long)m * k;
        // check if its possible to form m bouquet with k roses
        if(totalRosesNeeded > n){
            return -1;
        }

        // Fix the binary search range
        int minDay = INT_MAX;
        int maxDay = INT_MIN;
        for(int i=0; i<n; i++){
            minDay = min(minDay, bloomDay[i]);
            maxDay = max(maxDay, bloomDay[i]);
        }

        int left = minDay;
        int right = maxDay;
        int result = -1;

        while(left <= right){
            int mid = left + (right-left)/2;

            //find out midDay tak kitne bouquets ban sakte hain
            int bouquetCount = countBouquets(bloomDay, mid, k);

            if(bouquetCount >= m){
                result = mid; // potential answer
                right = mid-1;  // search for an even smaller value
            } else{ // enough bouquet nahi bane
                left = mid+1;   // zyada days chahiye
            }
        }
        return result;
    }
};