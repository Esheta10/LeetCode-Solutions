class Solution {
public:
    int minimumPushes(string word) {
        /*APPROACH-1
        //2,3,4,5,6,7,8,9
        unordered_map<int,int> mp;//You can use an array of size 10 also and use index 2 to 9
        int result = 0;
        int assign_key = 2;
        for(char &ch:word)
        {
            if(assign_key>9)// If the assign_key exceeds 9, reset it to 2 (keypad has keys from 2 to 9)
                assign_key=2;

            mp[assign_key]++; // Increment the push count for the current assign_key
            result += mp[assign_key]; // Add the current key's push count to the total result

            assign_key++;// Move to the next key (like pressing the next key on a keypad)
        }
        return result; // Return the total number of pushes required    */
        vector<int> mp(26,0);
        for(char &ch:word)
        {
            mp[ch-'a']=1;//Mentioned in qn, all letters will be distinct
        }
        sort(mp.begin(),mp.end(),greater<int>());//descending order of freq
        int result = 0;
        for(int i=0;i<26;i++)
        {
            int freq = mp[i];
            int press = i/8 +1;
            result += press * freq;
        }
        return result;
    }
};