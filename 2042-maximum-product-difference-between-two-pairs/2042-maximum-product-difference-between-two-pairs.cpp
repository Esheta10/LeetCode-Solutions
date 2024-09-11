class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int n=nums.size();
        

        return {(nums[0]*nums[1])-(nums[n-1]*nums[n-2])};

    }
};