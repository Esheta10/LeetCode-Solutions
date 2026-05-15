class Solution {
public:
    int reverseNum(int n){

        int temp = n;
        int rev = 0;

        while(temp > 0){

            int rem = temp%10;
            rev = rev*10 + rem;
            temp /= 10;
        }
        return rev;
    }
    int mirrorDistance(int n) {
        
        int reverse = reverseNum(n);

        return abs(n-reverse);
    }
};