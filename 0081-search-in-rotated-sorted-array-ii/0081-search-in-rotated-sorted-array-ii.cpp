class Solution {
public:
    int findPivot(vector<int>& nums, int &n){

        int left = 0;
        int right = n - 1;

        while(left < right && nums[left] == nums[left+1]) left++; // skip duplicates
        while(left < right && nums[right] == nums[right-1]) right--; // skip duplicates

        while(left < right){
            
            int mid = left + (right - left)/2;

            if(nums[mid] > nums[right])
                left = mid+1; // pivot must be towards right side
            else
                right = mid;
        }
        return left;
    }
    bool binarySearch(vector<int>& nums,int target, int left, int right){

        while(left <= right){

            int mid = left+(right-left)/2;

            if(nums[mid] == target)
                return true;
            else if(nums[mid] < target)
                left = mid+1;
            else
                right = mid-1;
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        
        int n = nums.size();

        int pivot = findPivot(nums, n);

        if(nums[pivot] == target)
            return true;

        if(binarySearch(nums, target, 0, pivot-1))
            return true;
        
        return binarySearch(nums, target, pivot+1, n-1);

    }
};