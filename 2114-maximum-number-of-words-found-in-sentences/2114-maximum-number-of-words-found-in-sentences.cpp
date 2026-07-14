class Solution {
public:
    int wordCount(string &str){
        int count=0;
        for(int i=0; i<str.size(); i++){
            if(str[i] == ' ')
                count++;
        }
        return count+1;
    }
    int mostWordsFound(vector<string>& sentences) {
        
        int max_words_count = 0;
        for(int i=0; i<sentences.size(); i++){
            int count = wordCount(sentences[i]);
            if(count > max_words_count){
                max_words_count = count;
            }
        }
        return max_words_count;
    }
};