class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int maxLen = -1;
        int curr = 1;

        for(int i=1; i<n; i++){

            int diff = nums[i] - nums[i-1];
            int expected = (curr % 2 == 1) ? 1 : -1;

            if(diff == expected) // extend the subarray
                curr++;

            else if(diff == 1)  //can't extend but valid window, reset and start once again
                curr = 2;
            else
                curr = 1; // total reset


            if(curr > 1)
                maxLen = max(maxLen, curr);
        }
        return maxLen;
    }
};