class Solution {
public:
    int minSteps(string s, string t) {
        int n =s.length();
        int ana1[26]={0};
        int ana2[26]={0};
        for(int i=0;i<n;i++)
        {
            ana1[s[i]-'a']++;
            ana2[t[i]-'a']++;
        }
        int result=0;
        for(int i=0;i<26;i++)
        {
            int freq_s=ana1[i];
            int freq_t=ana2[i];

            if(freq_t < freq_s)
                result += freq_s - freq_t;
        }
        return result;
    }
};