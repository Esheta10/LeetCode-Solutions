class Solution {
public:
    char findTheDifference(string s, string t) {
       /* APPROACH-1
       int XOR=0;
        for(char &ch:s)
        {
            XOR ^=ch;
        }
        for(char &ch:t)
        {
            XOR ^=ch;
        }
        return (char)XOR;*/
        /*APPROACH-2---->o(n)->space
        unordered_map<char,int> mp;
        for(char &ch:s)
            mp[ch]++;
        for(char &ch:t)
        {
            mp[ch]--;
            if(mp[ch]<0)
                return ch;
        }
        return 'x';//flow will never come here*/
        int sum_s=0,sum_t=0;
        for(char &ch:s)
            sum_s +=ch;
        for(char &ch:t)
            sum_t +=ch;
        //sum_t>sum_s
        return (char)(sum_t-sum_s);

    }
};