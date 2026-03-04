class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n = nums.size();
        
        int totalSum = 0;
        int maxSum = nums[0], curr_max_sum = nums[0];
        int minSum = nums[0], curr_min_sum = nums[0];

        for(int i=1; i<n; i++){

            totalSum += nums[i];

            curr_max_sum = max(curr_max_sum + nums[i], nums[i]);
            maxSum = max(maxSum, curr_max_sum);

            curr_min_sum = min(curr_min_sum + nums[i], nums[i]);
            minSum = min(minSum, curr_min_sum);
        }
        totalSum += nums[0];

        if(maxSum < 0)
            return maxSum; // all negatives, return the least negative

        return max(maxSum, totalSum - minSum);
    }
};