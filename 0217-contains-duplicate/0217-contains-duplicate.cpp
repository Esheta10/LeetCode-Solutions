class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> uniqueNums(nums.begin(), nums.end());

        return uniqueNums.size() < nums.size();
    }
};