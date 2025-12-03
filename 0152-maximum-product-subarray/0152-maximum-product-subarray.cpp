class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
      int n = nums.size();
      int maxSoFar = nums[0];
      int minSoFar = nums[0];
      int result = nums[0];

      for(int i=1;i<n;i++){

        int tempMax = maxSoFar;

        maxSoFar = max({nums[i], nums[i]*maxSoFar, nums[i]*minSoFar});
        minSoFar = min({nums[i], nums[i]*tempMax, nums[i]*minSoFar});

        result = max(result, maxSoFar);
      }

      return result;
    }
};