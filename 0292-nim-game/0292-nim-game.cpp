class Solution {
public:
    bool canWinNim(int n) {
        
        if(n%4 != 0)
            return true; // can win
        else
            return false; // will lose
    }
};