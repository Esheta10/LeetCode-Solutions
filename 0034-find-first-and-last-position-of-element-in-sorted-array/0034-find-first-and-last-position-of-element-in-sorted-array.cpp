class Solution {
public:
    int findLeftMost(vector<int> &nums, int &target, int &n){

        int left = 0;
        int right = n-1;

        int leftMost = -1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] == target){
                leftMost = mid; // could be potential answer
                right = mid -1; // still search further left
            } else if(nums[mid] > target){
                right = mid - 1;
            } else {
               left = mid + 1;
            }
        }
        return leftMost;
    }
    int  findRightMost(vector<int>& nums, int &target, int &n){

        int left = 0;
        int right = n-1;

        int rightMost = -1;

        while(left <= right){

            int mid = left + (right - left)/2;

            if(nums[mid] == target){
                rightMost = mid; // could be potentail answer
                left = mid + 1; // still search further right 
            } else if(nums[mid] < target){
                left = mid +1 ;
            } else {
                right = mid - 1;
            }
        }
        return rightMost;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        int leftMost = findLeftMost(nums, target, n);
        int rightMost = findRightMost(nums, target, n);

        return {leftMost, rightMost};
    }
};