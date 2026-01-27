class Solution {
public:
    int findFirst(vector<int>& nums, int target, int n){

        int leftMost = -1;

        int left = 0;
        int right = n-1;

        while(left <=  right){

            int mid = left + (right - left)/2;

            if(nums[mid] == target){
                leftMost = mid;
                right = mid-1; // search more towwards the left
            } else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return leftMost;
    }
    int findLast(vector<int>& nums, int target, int n){

        int rightMost = -1;
        int left = 0;
        int right = n-1;

        while(left <=  right){

            int mid = left + (right - left)/2;

            if(nums[mid] == target){
                rightMost = mid;
                left = mid + 1;// search more towards right
            } else if( nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return rightMost;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int first = findFirst(nums, target, n);
        int last = findLast(nums, target, n);

        return {first, last};
    }
};