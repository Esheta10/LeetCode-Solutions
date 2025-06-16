class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        unordered_set<char> st(allowed.begin(),allowed.end());

        int count=0;
        for(string &word : words)
        {
            bool allCharPresent=true;
            for(char &ch:word)
            {
                if(st.find(ch)==st.end())
                {
                allCharPresent = false;
                break;
                }
            }
            if(allCharPresent)
            count++;
        }

        return count;
    }
};