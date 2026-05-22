class Solution {
public:
    int getLeftMost(vector<int>& nums, int n, int target){

        int left = 0;
        int right = n-1;

        int leftMost = -1;

        while(left <= right){

            int mid = left + (right - left)/2;

            if(nums[mid] == target){
                leftMost = mid;
                right = mid-1;
            } else if(nums[mid] < target){
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return leftMost;
    }
    int getRightMost(vector<int>& nums, int n, int target){

        int left = 0;
        int right = n-1;

        int rightMost = -1;

        while(left <= right){

            int mid = left + (right - left)/2;

            if(nums[mid] == target){
                rightMost = mid;
                left = mid+1;
            } else if(nums[mid] > target){
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return rightMost;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();

        int left = getLeftMost(nums, n, target);
        int right = getRightMost(nums, n, target);

        return {left, right}; 
    }
};