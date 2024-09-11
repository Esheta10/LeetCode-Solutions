class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();

        int currentMax=nums[0];
        int maxSum=nums[0];

        int currentMin=nums[0];
        int minSum=nums[0];

        for(int i=1;i<n;i++)
        {
         
            currentMax = max(currentMax+nums[i],nums[i]);
            maxSum = max(maxSum, currentMax);

            currentMin=min(currentMin+nums[i],nums[i]);
            minSum = min(minSum,currentMin);
        }
        return max(abs(maxSum),abs(minSum));
    }
};