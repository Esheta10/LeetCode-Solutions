class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int n1 = nums[n-1] * nums[n-2] * nums[n-3];
        int n2 = nums[n-1] * nums[0] * nums[1];

        return max(n1,n2);
    }
};