class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {

        int n = nums.size();
        int totalFlips = 0;
        int currentFlipEffect = 0;
        vector<bool> flipStartedHere(n, false);


        for(int i=0; i<n; i++){

            if(i>=k && flipStartedHere[i-k] == true)
                currentFlipEffect--;


            int realValue = (currentFlipEffect % 2 == 0) ? nums[i] : 1-nums[i];

            if(realValue == 0){
                if(i+k > n)
                    return -1;

                flipStartedHere[i] = true;
                currentFlipEffect++;
                totalFlips++;
            }
        }
        return totalFlips;
    }
};