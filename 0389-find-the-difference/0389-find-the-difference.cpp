class Solution {
public:
    char findTheDifference(string s, string t) {
        
    /*  -----APPROACH-1-----
        unordered_map<char,int> mp;

        for(char &ch:s)
        {
            mp[ch]++;
        }
        for(char &ch:t)
        {
            mp[ch]--;
            if(mp[ch]<0)
                return ch;
        }
        return 'x';
        */
        /* -----APPROACH-2-----(doesn't satisfy all the test cases)
        unordered_map<char,int> mp;
        for(char &ch:s)
        {
            mp[ch]++;
        }
        for(char &ch:t)
        {
            if(mp.find(ch)==mp.end())//the given character is not present in the string,then return it
                return ch;
        }
        return 'x';
    */
    int sum_s=0,sum_t=0;
    for(char &ch:s)
        sum_s += ch;
    for(char &ch:t)
        sum_t += ch;

    return (char)(sum_t-sum_s);
    }
};