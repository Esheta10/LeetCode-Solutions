class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int m = s1.size();
        int n = s2.size();

        if(m > n)
            return false;

       // frequency vectors for s1 and the current window in s2
       vector<int> s1_freq(26, 0);
       vector<int> s2_freq(26, 0);

        // fill frequency of characters in s1
       for(char &ch : s1){
            s1_freq[ch-'a']++;
       }

       // slide the window over s2
       int i=0; // left index of the sliding window
       int j=0; // right index of the sliding window

       while(j<n){

            s2_freq[s2[j] - 'a']++; // include a new character from the right end of the window

            // check if the current window size matches the size of s1
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