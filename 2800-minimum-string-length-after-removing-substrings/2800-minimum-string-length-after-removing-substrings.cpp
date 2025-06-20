class Solution {
public:
    int minLength(string s) {
        int i=0;//write
        int j=1;//read

        int n = s.length();

        while(j<n)
        {
            if(i<0)
            {
                i++;
                s[i]=s[j];
                j++;
            }
            else if((s[i]=='A' && s[j]=='B') || (s[i]=='C' && s[j]=='D'))
            {
                i--;
                j++;
            }
            else
            {
                i++;
                s[i]=s[j];
                j++;
            }
        }
        return i+1;
    }
};