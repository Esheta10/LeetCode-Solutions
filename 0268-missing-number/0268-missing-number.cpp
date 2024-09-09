class Solution {
public:
    int missingNumber(vector<int>& nums) {
     /*  APPROACH-1
      int n=nums.size();
        int sum=n*(n+1)/2;
        for(int i=0;i<n;i++)
        {
            sum -=nums[i];
        }
        return sum; */
        /*APPROACH-2
        int n=nums.size();
        int result=n;
        for(int i=0;i<n;i++)
        {
            result ^= i;
            result ^= nums[i];
        }
        return result;  */
        /*APPROACH-3*/
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0, r=n-1;
        int result=n;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(nums[mid]>mid)
            {
                result=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return result;
    }
};