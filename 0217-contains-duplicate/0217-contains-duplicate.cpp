class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> st;
        int n = nums.size();

        for(int num: nums){

            if(st.count(num))   // duplicates exist
                return true;

            st.insert(num);
        }

        return false;
    }
};