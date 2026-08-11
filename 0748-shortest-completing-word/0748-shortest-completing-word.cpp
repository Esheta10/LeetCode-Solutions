class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        
        // pehle license plate mein letters ki frequency count karo
        int plateLetterCount[26] = {0};
        for(char c: licensePlate){
            if(isalpha(c))
                plateLetterCount[tolower(c)-'a']++;
        }

        string shortestWord = "";
        for(string &word: words){
            int wordCount[26] = {0};
            for(char c: word)
                wordCount[c-'a']++;

            bool isValid = true;
            for(int i=0; i<26; i++){
                if(wordCount[i] < plateLetterCount[i]) // saare letters present nahi hai word mein
                {
                    isValid = false;
                    break;
                }
            }
            if(isValid){
                if(shortestWord == "" || word.length() < shortestWord.length())
                    shortestWord = word;
            }
        }   
        return shortestWord;
    }
};