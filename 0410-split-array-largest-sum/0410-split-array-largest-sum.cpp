class Solution {
public:
    // check if we can split into k subarrays with maxSum limit
    bool canSplit(vector<int>& nums, int k, int maxSum){

        int subarrayNeeded = 1; // at least 1 subaaray
        int currentSum = 0;

        for(int i=0; i<nums.size(); i++){

            if(currentSum + nums[i] <= maxSum){
                currentSum += nums[i];
            } else {
                subarrayNeeded++;
                currentSum = nums[i];

                if(subarrayNeeded > k)
                    return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        
        int n = nums.size();

        int left = *max_element(nums.begin(), nums.end());
        int right = 0;

        for(int num: nums){
            right += num;
        }
        int result = right;

        while(left <= right){
            int mid = left + (right - left)/2;
            // Can we spilt with maxSum = mid?
            if(canSplit(nums, k, mid)){
                result = mid; //valid answer
                right = mid - 1; // try smaller
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};