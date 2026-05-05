class Solution {
public:
    vector<string> result;
    void backtrack(int idx, string &digits, string &temp, unordered_map<char, string> &mp){

        if(idx >= digits.length()){
            result.push_back(temp);
            return;
        }

        char ch = digits[idx];
        string str = mp[ch];

        for(int i=0; i<str.length(); i++){

            temp.push_back(str[i]); // CHOOSE
            backtrack(idx+1, digits, temp, mp); // RECURSE
            temp.pop_back();    // UN-CHOOSE
        }
    }
    vector<string> letterCombinations(string digits) {
        
        if(digits.length() == 0)
            return {};

        unordered_map<char, string> mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string temp = "";
        backtrack(0, digits, temp, mp);

        return result;
    }
};