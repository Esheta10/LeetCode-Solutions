class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size();

        // edge case: single element
        if(n==1)
            return 0;
        
        // check boundaries
        if(nums[0] > nums[1])
            return 0;
        
        if(nums[n-1] > nums[n-2])
            return n-1;

        // fix the binary search range
        int left = 1;
        int right = n-2;

        while(left <= right){

            int mid = left + (right-left)/2;

            if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1])
                return mid;
            // peak must be on right
            else if(nums[mid] < nums[mid+1])
                left = mid+1;
            // peak must be on left
            else
                right = mid-1;
        }
        return -1;
    }
};