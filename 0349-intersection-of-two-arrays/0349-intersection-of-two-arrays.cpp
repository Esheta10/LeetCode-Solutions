class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(),nums1.end());
        unordered_set<int> st2;
        
        for(int &num: nums2)
        {
            if(st1.find(num)!=st2.end())
                st2.insert(num);
        }
        vector<int> result;
        for(auto &it:st2)
        {
            result.push_back(it);
        }
        return result;
    }
};