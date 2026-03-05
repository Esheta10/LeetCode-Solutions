class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size();
        int totalFlips = 0;
        int currentFlipCount = 0;
        vector<bool> flipStartedHere(n, false);

        for(int i=0; i<n; i++){

            if(i>=3 && flipStartedHere[i-3] == true)
                currentFlipCount--;

            int realValue = (currentFlipCount % 2 == 0) ? nums[i] : 1-nums[i];

            if(realValue == 0){
                if(i+3>n)
                    return -1;

                flipStartedHere[i] = true;
                currentFlipCount++;
                totalFlips++;
            }
        }
        return totalFlips;
    }
};