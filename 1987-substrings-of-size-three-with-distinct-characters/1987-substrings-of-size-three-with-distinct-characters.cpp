class Solution {
public:
    int countGoodSubstrings(string s) {
        int n=s.length();
        int count=0;
         // Iterate over each possible starting index for substrings of length 3
        for(int i=0;i<=n-3;i++)
        {
            string substr=s.substr(i,3);// Extract the substring of length 3
            // Use a set to check for uniqueness
            unordered_set<char> charSet(substr.begin(),substr.end());
            if(charSet.size()==3)// If all characters are unique (set size is 3), increment count
            if (charSet.size() == 3) 
            {
                ++count;
            }
        }
        return count;
    }
};