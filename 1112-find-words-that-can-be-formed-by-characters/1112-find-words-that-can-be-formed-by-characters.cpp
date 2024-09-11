class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        // Count frequency of each character in chars
        vector<int> charCount(26,0);
        for(char &ch:chars)
            charCount[ch-'a']++;

        int result=0;
        // Process each word
        for(string &word:words)
        {   
            vector<int> wordCount(26,0);
            // Count frequency of each character in word
            for(char &ch:word)
                wordCount[ch-'a']++;
        
        bool ok=true;
        for(int i=0;i<26;i++)
        {
            if(wordCount[i]>charCount[i])
            {
                 ok=false;
                 break;
            }
        }
        // If word can be formed, add its length to the result
        if(ok==true)
            result += word.length(); 
    }
       return result;
    }
};