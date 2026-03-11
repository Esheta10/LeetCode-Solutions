class Solution {
public:
    int findPivot(vector<int>& nums, int left, int right){

        while(left < right){

            int mid = left + (right - left)/2;

            if(nums[mid] > nums[right])
                left = mid+1;   // pivot must be on right
            else
                right = mid; // right itself is pivot or may be it lies towards left
        }
        return left;
    }
    int binarySearch(vector<int>& nums, int target, int left, int right){

        while(left <= right){

            int mid = left + (right - left)/2;

            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();

        int pivot = findPivot(nums, 0, n-1);

        if(nums[pivot] == target)
            return pivot;

        int idx = -1;
        idx = binarySearch(nums, target, 0, pivot-1);

        if(idx != -1)
            return idx;
        
        idx = binarySearch(nums, target, pivot+1, n-1);

        return idx;
    }
};