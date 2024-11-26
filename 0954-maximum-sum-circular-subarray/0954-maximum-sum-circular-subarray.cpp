class Solution {
public:
int kadaneMax(const vector<int>& arr)
    {
    int maxSum = INT_MIN, currentSum = 0;
    for (int num : arr) {
        currentSum = max(num, currentSum + num);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
    }
    int kadaneMin(const vector<int>& arr)
    {
    int minSum = INT_MAX, currentSum = 0;
    for (int num : arr) {
        currentSum = min(num, currentSum + num);
        minSum = min(minSum, currentSum);
    }
    return minSum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
    int maxNormal = kadaneMax(nums);
    if (maxNormal < 0) // All elements are negative
        return maxNormal;

    int totalSum = 0;
    for (int num :nums)
        totalSum += num;

    int minSubarraySum = kadaneMin(nums);
    int maxCircular = totalSum - minSubarraySum;

    return max(maxNormal, maxCircular);
    }
};