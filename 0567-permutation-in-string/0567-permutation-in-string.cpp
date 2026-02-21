class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int m = s1.size();
        int n = s2.size();

        if(m > n)
            return false;
        
        vector<int> s1_freq(26,0);
        vector<int> s2_freq(26,0);

        for(char &ch : s1){
            s1_freq[ch - 'a']++;
        }

        int i=0, j=0;
        // i --> left index of the sliding window
        // j --> right index of the slididng window

        while(j<n){

            s2_freq[s2[j] - 'a']++; // include a new character from the right end of the window

            // check if the current window size matches the size of s1
            // if not / if it is greater than s1, then shrink the window
            if(j-i+1 > m){
                s2_freq[s2[i] - 'a']--;
                i++;
            }

            // check if current window's frequency matches s1's frequency
            if(s1_freq == s2_freq)
                return true;

            j++;
        }
        return false;
    }
};