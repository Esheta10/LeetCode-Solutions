class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> wordcount;
        vector<string> result;

        stringstream ssA(s1);
        string token;
        while(ssA >> token)
        {
            wordcount[token]++;
        }
        stringstream ssB(s2);
        while(ssB >> token)
        {
            wordcount[token]++;
        }
        for(const auto &entry:wordcount)
        {
            if(entry.second==1)
                result.push_back(entry.first);
        }
        return result;
    }
};