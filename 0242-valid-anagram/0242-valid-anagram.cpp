class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        unordered_map<char,int> countS,countT;
        for(char ch:s)
            countS[ch]++;
        for(char ch:t)
            countT[ch]++;
        
        return countS==countT;
    }
};