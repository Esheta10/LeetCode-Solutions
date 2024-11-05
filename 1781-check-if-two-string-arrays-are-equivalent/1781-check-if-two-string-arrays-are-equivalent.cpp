class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        //Approach-1 (Simple concatenation)
        //T.C : O(n*k) - n and m = length of word1 and word2 respectively
        //S.C : O(n+k)
       /* string s1 = "";
        string s2 = "";

        for(string &s:word1)
        {
            s1 += s;
        }
        for(string &s:word2)
        {
            s2 += s;
        }
        return s1==s2;*/
        int m=word1.size();
        int n=word2.size();

        int w1i=0,i=0;
        int w2i=0,j=0;
        while(w1i<m && w2i<n)
        {
            if(word1[w1i][i]!=word2[w2i][j])
                return false;

            i++;
            j++;

            if(i==word1[w1i].length())
            {
                i=0;
                w1i++;
            }
            if(j==word2[w2i].length())
            {
                j=0;
                w2i++;
            }
            if(w1i==word1.size() && w2i==word2.size())
                return true;
        }
        return false;
        //Approach-2 (Using comparison character by character using index)
        //T.C : O(n*k) - n and m = length of word1 and word2 respectively
        //S.C : O(1)
//Both the approaches take same T.C hence approach-1 is more ideal
    }
};