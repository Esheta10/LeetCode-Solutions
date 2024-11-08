class Solution {
public:
    string defangIPaddr(string address) {
        stringstream ss(address); // Create a stringstream to split the address into words
        string token="";
        string result="";
        vector<string> words;
// Split the string into words by '.' delimiter
        while (getline(ss,token,'.'))
        {
            if(!token.empty())
                words.push_back(token);// Add the non-empty tokens (substrings) to words
        }
        // Combine the words back with '[.]' between them
        for(int i=0;i<words.size();i++)
        {
            result += words[i];// Add word to result
            if(i!=words.size()-1)// Add "[.]" between words
                result += "[.]";
        }
        return result;
    }
};