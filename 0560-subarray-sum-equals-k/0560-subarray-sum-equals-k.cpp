class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Brute - Force Approach
        // int n = nums.size();
        // int count = 0;
        // for(int s=0;s<=n-1;s++){
        //     for(int e=s; e<=n-1;e++){
        //         int sum = 0;
        //         for(int i=s;i<=e;i++){
        //             sum += nums[i];
        //         }
        //         if(sum == k)
        //             count++;
        //     }
        // }

        // return count;

        // Optimal Approach

        int n = nums.size();

        unordered_map<int,int> mp;
        mp.insert({0,1});

        int result = 0;
        int cumSum = 0;

        for(int i=0;i<n;i++){
            
            cumSum += nums[i];
            if(mp.find(cumSum-k) != mp.end())
                result +=  mp[cumSum-k];

            mp[cumSum]++;
        }
        return result;
    }
};