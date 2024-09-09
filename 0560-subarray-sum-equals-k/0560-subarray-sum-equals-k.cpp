class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        int result=0;
        int CumSum=0;
        mp.insert({0,1});
        for(int i=0;i<nums.size();i++)
        {
            CumSum += nums[i];
            if(mp.find(CumSum-k)!=mp.end())
            {
                result += mp[CumSum-k];
            }
            mp[CumSum]++;
        }
        return result;

    }
};