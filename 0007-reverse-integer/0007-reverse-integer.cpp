class Solution {
public:
    int reverse(int x) {
        unsigned int rev=0;
        int sign = x < 0 ? -1 : 1;
        x = abs(x);  // Work with positive value for simplicity
        while(x>0)
        {
            int digit=x%10;
            if (rev > (INT_MAX - digit) / 10)
            {
                 return 0;  // Overflow occurred
            }
            rev=rev*10+digit;
            x=x/10;

        }
        return rev*sign;
    }
};