class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.length();
        int count = 0;
        map<char,vector<int>> mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]].push_back(i);
        }
        for(string &word:words)
        {
            int prev=-1;
            bool found = true;
            for(char &ch:word)
            {
                if(mp.find(ch)==mp.end())
                {
                    found = false;
                     break;
                }
                auto it = upper_bound(mp[ch].begin(),mp[ch].end(),prev);

                if(it==mp[ch].end())
                {
                 found=false;
                 break;
                }
                 prev = *it;
            }
             if(found)
                count++;
        }
        return count;
    }
};