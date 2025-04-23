class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        /* APPROACH-1: Using unordered map
        unordered_map<int,int> mp;
        for(int &num:nums1)
        {
            mp[num]++;
        }
        for(int &num:nums2)
        {
            if(mp.find(num)!=mp.end())
                return num;
        }
        return -1;*/
        //APPROACH-2: Using unordered set
        unordered_set<int> st(nums1.begin(),nums1.end());
        for(int &num: nums2)
        {
            if(st.find(num)!=st.end())
                return num;
        }
        return -1;
        
    }
};