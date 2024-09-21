class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask=0;//000000000000000

        for(char &ch : allowed)
        {
            mask |= (1 << (ch-'a'));
        }
        int count=0;
        for(string &word : words)
        {
            bool allCharacterPresent=true;
            for(char &ch : word)
            {
                if((mask >> (ch-'a') & 1) == 0)
                {
                    allCharacterPresent=false;
                    break;
                }
            }
            if(allCharacterPresent==true)
                    count++;
        }
        return count;
    }
};