class Solution {
public:
    typedef pair<int,int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // 1. store the element and its freq in map
        unordered_map<int,int> mp;
        for(int num: nums){
            mp[num]++;
        }


        //2. Create a min-heap to have top-k elements at top
        priority_queue<P, vector<P>, greater<P>> pq;

        //3. Store elements in min-heap
        for(auto& it: mp){
            int value = it.first;
            int freq = it.second;

            pq.push({freq, value});

            if(pq.size() > k){
                pq.pop();
            }
        }
        //4.result
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};