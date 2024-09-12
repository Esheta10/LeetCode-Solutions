class Solution {
public:
    bool makeEqual(vector<string>& words) {
       /*APPROACH-1
        int n=words.size();
        unordered_map<char,int> mp;
        for(string &word:words)
        {
            for(char &ch:word)
                mp[ch]++;
        }
        for(auto &it:mp)
        {
            //char ch=it.first;
            int freq=it.second;
            if(freq % n != 0)
                return false;
        }
        return true;*/
        int n=words.size();
        int count[26]={0};
       for(string &word:words)
       {
        for(char &ch:word)
            count[ch-'a']++;
       }
        for(auto &freq:count)
        {
            if(freq % n != 0)
                return false;
        }
        return true;
    }
};