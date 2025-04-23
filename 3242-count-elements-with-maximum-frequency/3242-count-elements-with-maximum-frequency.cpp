class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxFreq=0;
        int result=0;
        for(int &num:nums)
        {
            mp[num]++;
            maxFreq=max(maxFreq,mp[num]);
        }
        for(auto &it:mp)
        {
            if(it.second==maxFreq)
                result += maxFreq;
        }
        return result;
    }
};