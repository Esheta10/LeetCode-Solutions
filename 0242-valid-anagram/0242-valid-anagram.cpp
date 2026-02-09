class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // check if length's are equal
        if(s.length() != t.length())
            return false;

        unordered_map<char,int> mp;

        //Count frequencies in string s
        for(char c: s){
            mp[c]++;
        }

        // Count frequencies in string t
        for(char c: t){
            mp[c]--;

            if(mp[c] < 0)  // character not in s, or in excess in t
                return false;
        }
        return true;
    }
};