class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        
        unordered_map<int, int> mp;
        
        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2(nums2.begin(), nums2.end());
        unordered_set<int> st3(nums3.begin(), nums3.end());

        for(int num: st1){
            mp[num]++;
        }
        for(int num: st2){
            mp[num]++;
        }
        for(int num: st3){
            mp[num]++;
        }

        vector<int> result;
        for(auto &it: mp){

            if(it.second >= 2)
                result.push_back(it.first);

        }
        return result;
    }
};