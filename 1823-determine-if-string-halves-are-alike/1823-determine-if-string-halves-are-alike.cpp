class Solution {
public:
    bool isVowel(char &ch)
    {
        return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
                ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U');
    }
    bool halvesAreAlike(string s) {
        int n = s.length();
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
        return countLeft==countRight;
    }
};