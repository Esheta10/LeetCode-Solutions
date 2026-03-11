class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();

        int left = 0;
        int right = n-1;

        while(left < right){

            int mid = left + (right - left)/2;

            if(mid % 2 == 1) // if mid is odd, make it even
                mid--;

            if(nums[mid] == nums[mid+1]){
                // order is intact, check towards right for single element
                left = mid + 2;
            } else {
                // nums[mid] != nums[mid+1] --> order is broken, either mid itself is single element or it lies towards left
                right = mid;
            }
        }
        return nums[right];
    }
};