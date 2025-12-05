class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();

        int oddCount = 0;
        int result = 0;

        unordered_map<int,int> mp;
        mp[oddCount] = 1;

        for(int i=0;i<n;i++){

            oddCount += (nums[i]%2 == 0) ? 0 : 1;

            if(mp.find(oddCount-k) != mp.end())
                result += mp[oddCount-k];


            mp[oddCount]++;
        }
        return result;
    }
};