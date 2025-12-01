class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int count = 0, max1 = 0;

        for(int num : nums){

            if(num == 1){
                count++;
                max1 = max(max1,count);
            }
            else {
                count = 0;
            }
        }
        return max1;
    }
};