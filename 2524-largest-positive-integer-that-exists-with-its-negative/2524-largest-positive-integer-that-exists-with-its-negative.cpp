class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        int maxi=-1;
        while(i<=j)
        {
            if(-nums[i]==nums[j])
            {
                maxi=max(maxi,nums[j]);
                i++;
                j--;
            }
            else if(-nums[i]<nums[j])
                j--;
            else
                i++;
        }
    return maxi;
    }
};