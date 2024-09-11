class Solution {
public:
    int KadanesMax(vector<int>& nums,int n)
    {
        int sum=nums[0];
        int maxSum=nums[0];
        for(int i=1;i<n;i++)
        {
            sum=max(sum+nums[i],nums[i]);
            maxSum=max(maxSum,sum);
        }
        return maxSum;
    }
    int KadanesMin(vector<int>& nums,int n)
    {
        int sum=nums[0];
        int minSum=nums[0];
        for(int i=1;i<n;i++)
        {
            sum=min(sum+nums[i],nums[i]);
            minSum=min(minSum,sum);
        }
        return minSum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        //1.total sum
        int SUM=accumulate(nums.begin(),nums.end(),0);
        //2.minSum
        int minSum=KadanesMin(nums,n);
        //3.maxSum
        int maxSum=KadanesMax(nums,n);//case-1
        //4.circular_sum = SUM-minNSum
        int circular_sum = SUM - minSum;
        if(maxSum>0)
            return max(maxSum,circular_sum);
        
        return maxSum;
    }
};