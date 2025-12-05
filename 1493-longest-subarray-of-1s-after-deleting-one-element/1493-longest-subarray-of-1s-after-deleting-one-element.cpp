class Solution {
public:
    // BRUTE FORCE APPROACH
    // int n;
    // int findMax(vector<int>&nums, int skip_idx){

    //     int currLength = 0;
    //     int maxLength = 0;

    //     for(int i=0;i<n;i++){

    //         if(i == skip_idx)
    //             continue;

    //         if(nums[i] == 1){
    //             currLength++;
    //             maxLength = max(maxLength,currLength);
    //         }else{  // nums[i] == 0
    //             currLength = 0;
    //         }
    //     }
    //     return maxLength;
    // }
    int longestSubarray(vector<int>& nums) {
        
        // n = nums.size();
        // int result = 0;
        // int countZero = 0;

        // for(int i=0;i<n;i++){
            
        //     if(nums[i] == 0){
        //         countZero++;
        //         result = max(result, findMax(nums,i));
        //     }
        // }
        // if(countZero == 0)
        //     return n-1;

        // return result;

        int n = nums.size();
        int left=0;
        int countZero = 0;
        int maxLen = 0;

        for(int right=0; right<n; right++){

            if(nums[right] == 0)
                countZero++;

            while(countZero >  1){

                if(nums[left] == 0){
                    countZero--;
                }
                left++;
            }
            maxLen = max(maxLen, right-left);
        }
        return maxLen;
    }
};