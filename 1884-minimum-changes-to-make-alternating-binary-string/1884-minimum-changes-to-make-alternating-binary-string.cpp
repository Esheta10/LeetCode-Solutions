class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        int start_with_0=0;
        int start_with_1=0;
        for(int i=0;i<n;i++)
        {
            char expected_char_0 = (i%2==0) ? '0' : '1';
            char expected_char_1 = (i%2==0) ? '1' : '0';

            if(s[i]!=expected_char_0)   start_with_0++;
            if(s[i]!=expected_char_1)   start_with_1++;
        }
        return min(start_with_0,start_with_1);
    }
};