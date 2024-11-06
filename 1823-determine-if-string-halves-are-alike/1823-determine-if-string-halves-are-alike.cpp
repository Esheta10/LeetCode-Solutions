class Solution {
public:
    //Approach-1 (without Using Set)
    //T.C : O(n)
    //S.C : O(1)
   /* bool isVowel(char &ch)
    {
        return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
                ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U');
    } */
    bool halvesAreAlike(string s) {
    /*  int n = s.length();
        int mid=n/2;
        int i=0,j=mid;
        int countLeft=0;
        int countRight=0;
        while(i<mid && j<n)
        {
            if(isVowel(s[i]))
                countLeft++;
            if(isVowel(s[j]))
                countRight++;
            
            i++;
            j++;
        }
        return countLeft==countRight;   */
        int n=s.length();
        int mid=n/2;
        int i=0,j=mid;

        int countLeft=0,countRight=0;
        string vowels="aeiouAEIOU";
        unordered_set<char> st(vowels.begin(),vowels.end());

        while(i<mid && j<n)
        {
            if(st.find(s[i])!=st.end())
                countLeft++;
            if(st.find(s[j])!=st.end())
                countRight++;
            
            i++;
            j++;
        }
        return countLeft==countRight;

    }
};
