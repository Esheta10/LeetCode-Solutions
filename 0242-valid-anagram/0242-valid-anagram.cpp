class Solution {
public:
    bool isAnagram(string s, string t) {
        /*approach-1
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        return s==t;*/
        vector<int> count(26,0);
        for(char ch:s)
        {
            count[ch-'a']++;
        }
        for(char ch:t)
        {
            count[ch-'a']--;
        }
        //check if all the elements in count are zero
        bool allZeroes = all_of(count.begin(),count.end(),[](int element)
        {
            return element == 0;
        });
        return allZeroes;
    }
};