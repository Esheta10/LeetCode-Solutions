class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int num:nums)
        {
            // Check if the number is already in the set
            if(seen.find(num)!=seen.end())
                return true;// Duplicate found
            seen.insert(num); // Add the number to the set
        }
        return false;// No duplicates found
    }

};