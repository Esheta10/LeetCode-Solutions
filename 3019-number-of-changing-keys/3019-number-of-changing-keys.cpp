class Solution {
public:
    int countKeyChanges(string s) {
        
        int n = s.size();

        for(int i=0; i<n; i++){

            s[i] = tolower(s[i]);
        }

        int count = 0;
        for(int i=1; i<n; i++){

            if(s[i] != s[i-1])
                count++;
        }
        return count;
    }
};