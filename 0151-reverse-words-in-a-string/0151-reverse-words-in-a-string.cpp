class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token="";
        string result = "";
        vector<string> words;

        while (getline(ss, token, ' ')) 
        {
            if(!token.empty())
                words.push_back(token);
        }
        for(int i=words.size()-1;i>=0;--i)
        {
            result += words[i];
            if(i!=0)
                result += " ";
        }
        return result;
    }
};