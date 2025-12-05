class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();

        int currentCount = 0;
        int maxCount = 0;


        for(int num : nums){

            if(num == 1){
                currentCount++;
                maxCount = max(currentCount, maxCount);
            } else {
                currentCount = 0;
            }
        }
        return maxCount;
    }
};