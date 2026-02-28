class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        
        int n = nums.size();

        int maxDiff = -1;
        int minSoFar = nums[0];

        for(int i=1; i<n; i++){

            if(nums[i] > minSoFar){
                maxDiff = max(maxDiff, nums[i] - minSoFar);
            }

            minSoFar = min(minSoFar, nums[i]);
        }
        return maxDiff;
    }
};