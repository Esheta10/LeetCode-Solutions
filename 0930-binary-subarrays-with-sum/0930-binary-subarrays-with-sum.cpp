class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int count = 0;
        int prefixSum = 0;

        int n = nums.size();

        unordered_map<int,int> mp;  // hashmap : prefixSum kitni baar aaya
        mp[0] = 1;

        for(int i=0;i<n;i++){

            prefixSum += nums[i];   // current prefixSum calculate karo

            int target = prefixSum - goal;

            if(mp.find(target) != mp.end())
                count += mp[target]; // jitne baar dekha, utna subarrays

            mp[prefixSum]++;    // current prefixSum ko map mein add karo
        }

        return count;
    }
};