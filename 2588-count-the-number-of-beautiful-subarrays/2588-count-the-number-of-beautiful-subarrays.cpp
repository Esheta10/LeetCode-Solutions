class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> mp; // prefixXOR ---> frequency
        mp[0] = 1;

        long long currXOR = 0;
        long long count = 0;

        for(int i=0; i<n; i++){

            currXOR ^= nums[i];
            int need = currXOR ^ 0;

            if(mp.find(need) != mp.end())
                count += mp[need];

            mp[currXOR]++;
        }
        return count;
    }
};