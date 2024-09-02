class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int totalSum=n*(n+1)/2;
        int arraySum=0;
        for(int num:nums)
        {
            arraySum += num;
        }
        return totalSum-arraySum;
    }
};