class Solution {
public:
    int t[301];
    unordered_set<string> st;
    bool solve(int idx, string& s)
    {
        int n = s.length();
        if(idx==n)
            return true;
        if(st.find(s)!= st.end())   return true;
        
        if(t[idx] != -1)
            return t[idx];
        for(int l=1;l<=n;l++)
        {
            string temp = s.substr(idx,l);

            if(st.find(temp)!=st.end() && solve(idx+l,s))
                return t[idx]=true;
        }
        return t[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        memset(t,-1,sizeof(t));
        for(string word: wordDict)
            st.insert(word);

        return solve(0,s);
    }
};