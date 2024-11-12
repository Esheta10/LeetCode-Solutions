class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
       unordered_map<string, int> mp;
        
        // Step 1: Store frequency of each word
        for (string &word : words) {
            mp[word]++;
        }
        
        // Step 2: Populate the vector with {word, freq} pairs
        vector<pair<string, int>> vec(mp.begin(), mp.end());
        
        // Step 3: Sort the vector with a custom comparator
        auto lambda = [](pair<string, int> &p1, pair<string, int> &p2) {
            if (p1.second == p2.second)
                return p1.first < p2.first;  // Lexicographical order if frequencies are equal
            return p1.second > p2.second;   // Higher frequency comes first
        };
        sort(vec.begin(), vec.end(), lambda);
        
        // Step 4: Pick the top-k frequent words
        vector<string> result(k);
        for (int i = 0; i < k; ++i) {
            result[i] = vec[i].first;  // Store the word, not the frequency
        }
        
        return result;
    }
};