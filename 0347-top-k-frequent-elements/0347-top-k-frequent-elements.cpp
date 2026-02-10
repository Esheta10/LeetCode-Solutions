class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();

        // Frequency count
        unordered_map<int, int> mp;
        for(int num: nums){
            mp[num]++;
        }

        // create buckets
        vector<vector<int>> buckets(n+1);

        // fill the buckets
        for(auto &it : mp){
            int element = it.first;
            int freq = it.second;

            buckets[freq].push_back(element);
        }

        // extract top K elements from right to left
        vector<int> result;
        for(int i=n; i>=0 && result.size() < k; i--){
            for(int num: buckets[i]){
                result.push_back(num);
                if(result.size() == k){
                    return result;
                }
            }
        }
        return result;
    }
};