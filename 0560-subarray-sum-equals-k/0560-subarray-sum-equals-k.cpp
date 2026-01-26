class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();

        unordered_map<int,int> mp; // store {sum, freuency}
        mp[0] = 1; // means sum=0 appeared once, before we start

        int sum = 0;
        int count = 0;

        for(int i=0; i<n; i++){
            
            sum += nums[i];

            if(mp.find(sum-k) != mp.end()) // means, we have earlier seen the subarray sum in map
                count += mp[sum-k];

            mp[sum]++; // store the current sum frequency in map
        }
        return count;
    }
};