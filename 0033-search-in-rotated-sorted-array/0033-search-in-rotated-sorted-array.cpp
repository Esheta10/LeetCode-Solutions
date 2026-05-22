class Solution {
public:
    int findPivot(vector<int>& nums, int n){

        int left = 0;
        int right = n-1;

        while(left < right){

            int mid = left + (right-left)/2;

            if(nums[mid] > nums[right]){
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return right;
    }
    int binarySearch(vector<int>& nums, int left, int right, int target){

            int idx = -1;
            while(left <= right){

                int mid = left + (right - left)/2;

                if(nums[mid] == target){
                    idx = mid;
                    break;
                }
                else if(nums[mid] < target)
                    left = mid+1;
                else
                    right = mid-1;
            }
         return idx;
    }
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();

        int pivot_index = findPivot(nums,n);


       
        int idx = binarySearch(nums, 0, pivot_index-1, target);

        if(idx != -1)
            return idx;

        idx = binarySearch(nums, pivot_index, n-1, target);

        return idx;
    }
};