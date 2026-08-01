class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        long long pos = 0;
        for(char &ch : columnTitle){
            pos = pos * 26 + (ch - 'A' + 1);
        }
        return pos;
    }
};