class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();
        int left = 0;
        int right = n-1;

        int ans = n;

        while(left <= right){

            int mid = left + (right - left)/2;

            if(nums[mid] >= target){
                ans = mid;  // potential answer
                right = mid-1; // still serach left to find an even smaller value where nums[mid] >= x
            } else {
                left = mid+1;
            }
        }
        return ans;
    }
};