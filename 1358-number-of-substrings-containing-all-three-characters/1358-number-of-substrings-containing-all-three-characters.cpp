class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int left = 0, right = 0;
        int freq[3] = {0,0,0};

        int total = 0;
        while(right < n){
            // expand window
            freq[s[right] - 'a']++;

            // shrink from left if the window is valid
            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
                    total += n - right;

                    freq[s[left] - 'a']--;
                    left++;
            }
            right++;
        }
        return total;
    }
};