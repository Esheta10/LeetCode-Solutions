class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        
        int n = nums.size();
        int maxLen = 0;
        int curr = 0;

        for(int i=0; i<n; i++){

            if(nums[i] > threshold){
                curr = 0; // threshold violated, rest the streak
                continue;
            }
            if(nums[i] % 2 == 0 && curr == 0) // valid even start
                curr = 1;   
            else if(curr > 0 && (nums[i] % 2) != (nums[i-1] % 2)) // alternating btw odd-even or vice-versa
                curr++;
            else if(nums[i] % 2 == 0) // restart at new even element
                curr = 1;
            else // odd with no valid window before it
                curr = 0;

            maxLen = max(maxLen, curr);
        }
        return maxLen;
    }
};