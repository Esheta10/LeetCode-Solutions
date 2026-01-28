class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int l = 0;
        int r = n-1;

        while(l < r){

            int mid = l + (r - l)/2;

            if(nums[mid] > nums[r]){
                l = mid + 1; // right side mein minimum value hoga
            } else {    // nums[mid] <= nums[r]
                r = mid;    // inimum left side mein hai, ya ye khud minimum hai
            }
        }
        return nums[r];
    }
};