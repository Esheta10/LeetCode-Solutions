class Solution {
public:
    int findLeftMost(vector<int>& nums,int target,int n)
    {
        int l=0,r=n-1;
        int left_most = -1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid]==target)
            {
                left_most = mid;//possibly my answer
                r = mid-1;//look more on left
            }
            else if(nums[mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        return left_most;

    }
    int findRightMost(vector<int>& nums,int target,int n)
    {
        int l=0,r=n-1;
        int right_most = -1;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(nums[mid]==target)
            {
                right_most=mid;//posiibly my answer
                l=mid+1;//look more on right
            }
            else if(nums[mid]<target)
                l=mid+1;
            else 
                r=mid-1;
        }
        return right_most;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int left_most = findLeftMost(nums,target,n);
        int right_most = findRightMost(nums,target,n);

        return {left_most,right_most};
    }
};