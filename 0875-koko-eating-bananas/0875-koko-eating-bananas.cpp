class Solution {
public:
    bool canEatAllBananas(vector<int>& piles, int h, int mid){

        int actualHours = 0;

        for(int &pile : piles){

            actualHours += pile / mid; // hours

            if(pile % mid != 0)
                actualHours++;
        }
        return actualHours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while(left < right){

            int mid = left + (right - left)/2;

            if(canEatAllBananas(piles, h, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};