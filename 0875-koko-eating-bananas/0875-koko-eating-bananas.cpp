class Solution {
public:
    // check if koko can finish all banana piles in h hours at speed mid
    bool canEatAllBananas(vector<int>& piles, int h, int mid){

        int actualHours = 0;

        for(int &pile : piles){

            actualHours += pile / mid; // full hours for this pile 

            if(pile % mid != 0)
                actualHours++; // leftover bananas ? +1 hour
        }
        return actualHours <= h; // can she finish in time ?
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int left = 1; // min speed
        int right = *max_element(piles.begin(), piles.end()); // max speed in worst case scenario

        while(left < right){

            int mid = left + (right - left)/2; // candidate speed

            if(canEatAllBananas(piles, h, mid))
                right = mid; // speed works, try smaller
            else
                left = mid + 1; // too slow, need faster
        }
        return left; // minimum valid speed
    }
};