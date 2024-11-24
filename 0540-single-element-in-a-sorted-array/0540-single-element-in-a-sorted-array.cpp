class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //Approach-1:XOR Operation:-(O(n))
        int result=0; 
        for(int i=0;i<nums.size();i++)
        {
            result ^= nums[i];
        }
        return result;
        //Approach-2:Binary Search:-O(log(n))
        int l=0;
        int h=nums.size()-1;
        while(l<h)
        {
            int mid=l+(h-l)/2;
            if(mid % 2 == 0)//mid is even
            {
                if(nums[mid]==nums[mid+1])
                    l=mid+2;
                    else
                    h=mid;
            }
            else//mid is odd
            {
                if(nums[mid]==nums[mid-1])
                    l=mid+1;
                else
                    h=mid;
            }
        }
        return nums[l];
    }
};