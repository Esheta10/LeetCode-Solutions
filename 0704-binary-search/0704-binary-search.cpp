class Solution {
public:
    int solve(vector<int>& nums, int left, int right, int target){

        if(left > right)
            return -1;

        int mid = left + (right - left)/2;

        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            return solve(nums, mid+1, right, target);
        else
            return solve(nums, left, mid-1, target);
        
    }
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();

        return solve(nums, 0, n-1, target);
    }
};