class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        
        int n = nums.size();

        unordered_map<int,int> mp;
        mp[0] = 1;

        long long currentXor = 0;
        long long count = 0;

        for(int i=0; i<n; i++){

            currentXor ^= nums[i];

            long long requiredXor = currentXor ^ 0;

            if(mp.find(requiredXor) != mp.end())
                count += mp[requiredXor];

            mp[currentXor]++;
        }
        return count;
    }
};