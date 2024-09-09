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
        /*APPROACH-2*/
        int n=nums.size();
        int result=n;
        for(int i=0;i<n;i++)
        {
            result ^= i;
            result ^= nums[i];
        }
        return result;
    }
};