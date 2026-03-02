class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

       int left = 0;
       int best_streak = 0;
       int zeros = 0;

        int n = nums.size();

       for(int right = 0; right<n; right++){

            if(nums[right] == 0)
                zeros++;

            if(zeros > k){  // shrink the window
                if(nums[left] == 0)
                    zeros--;
                left++;
            }
            best_streak = max(best_streak, right - left + 1);    
       }
       return best_streak;
    }
};