class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        
        int maxLen = 0;
        int n = nums.size();


        for(int l=0; l<n; l++){

            if(nums[l] % 2 != 0)    // not even
                continue;
            if(nums[l] > threshold) // nums[l] <= threshold
                continue;
            
            int len = 1;
            for(int r=l+1; r<n; r++){

                if(nums[r] > threshold )
                    break;

                if((nums[r] % 2) == (nums[r-1] % 2))
                    break;

                len++;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};