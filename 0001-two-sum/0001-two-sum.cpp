class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();

        unordered_map<int,int> mp;

        for(int i=0; i<n;i++){

            int remaining = target - nums[i];
            if(mp.find(remaining) != mp.end())
                return {mp[remaining], i};  // store the remaining element's index, already present in map , current index

            mp[nums[i]] = i;// if not found, store the current element and its index
        }
        return {-1,-1};
    }
};