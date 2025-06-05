class Solution {
public:
    string reversePrefix(string word, char ch) {
        /*Approach-1
        int i=0;
        int j=word.find(ch);
        while(i<j)
        {
            swap(word[i],word[j]);
            i++;
            j--;
        }
        return word;*/
        /*Approach-2*/
        reverse(word.begin(),word.begin()+word.find(ch)+1);
        return word;
    }
};