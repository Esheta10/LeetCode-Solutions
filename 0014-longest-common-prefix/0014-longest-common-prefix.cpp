class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";//return empty string if input is empty
        string prefix=strs[0];//start with first string as the prefix
        for(int i=1;i<strs.size();i++)
        {
            while(strs[i].find(prefix)!=0)//check if the current string start with the prefix
                prefix=prefix.substr(0,prefix.size()-1);//reduce the prefix by one character

            if(strs.empty())// If the prefix becomes empty, return an empty string
                return "";
        }
        return prefix; // Return the longest common prefix
    }
};