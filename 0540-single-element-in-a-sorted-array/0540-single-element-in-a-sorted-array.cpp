class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();

        int l=0;
        int r=n-1;

        while(l<r){
            int mid = l+(r-l)/2;

            if(mid % 2 == 0){   // mid is even

                if(nums[mid] == nums[mid+1])
                    l = mid+1; // single element is on right side
                else 
                    r = mid;
            } else {
                // mid is odd
                if(nums[mid] == nums[mid-1])
                    l = mid+1; // single element is on right side
                else
                    r = mid;
            }

        }

        return nums[r];
    }
};