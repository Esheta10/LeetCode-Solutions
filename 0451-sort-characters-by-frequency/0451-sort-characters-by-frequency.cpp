class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> mp; // {char, freq}

        for(char c: s){
            mp[c]++;
        }
        // create a frequency vector
        vector<pair<int, char>> freqVec;
        for(auto [value, freq] : mp){
            freqVec.push_back({freq, value});
        }
        sort(freqVec.begin(), freqVec.end(), [](auto a, auto b){
            
            if(a.first != b.first)  // if a's freq is more than b
                return a.first > b.first;

            return a.second < b.second; // if both have same frequency then return the smaller one first
        });

        int idx = 0;
        for(auto it : freqVec){
            for(int i=0; i<it.first; i++)
                s[idx++] = it.second;
        }
        return s;
    }
};