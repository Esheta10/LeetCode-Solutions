class Solution {
public:
    bool isPalindrome(int x) {
        
       long long temp = x;
       long long rev=0;

        while(x>0){

            long long lastDigit = x%10;
            rev = rev*10 + lastDigit;
            x = x/10;
        }
        return rev == temp;
    }
};