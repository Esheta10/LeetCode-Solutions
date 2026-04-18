class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_set<int> st;

        long long windowSum = 0, maxSum = 0;
        int left = 0;

        for(int right = 0; right < n; right++){

            // if duplicates found, shrink from left until it's gone
            while(st.find(nums[right]) != st.end()){

                st.erase(nums[left]);
                windowSum -= nums[left];
                left++;
            }

            // add new element
            st.insert(nums[right]);
            windowSum += nums[right];

            // check if window size is exactly k
            if(right-left+1 == k){

                maxSum = max(maxSum, windowSum);
                // shrink window by 1 from left for next iteration
                st.erase(nums[left]);
                windowSum -= nums[left];
                left++;
            }

        }
        return maxSum;
    }
};