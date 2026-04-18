class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n = nums.size();
        int max_sum = nums[0], curr_max_sum = nums[0];
        int min_sum = nums[0], curr_min_sum = nums[0];
        int totalSum = 0;

        for(int i=1; i<n; i++){

            totalSum += nums[i];
            curr_max_sum = max(curr_max_sum + nums[i], nums[i]);
            max_sum = max(max_sum, curr_max_sum);

            curr_min_sum = min(curr_min_sum + nums[i], nums[i]);
            min_sum = min(min_sum, curr_min_sum);
        }
        totalSum += nums[0];

        if(max_sum <0)
            return max_sum;

        return max(max_sum, totalSum - min_sum);

    }
};