class Solution {
public:
    string toHex(int num) {
        if(num == 0)
            return "0";
        
        unsigned int n = num;
        string hexChars = "0123456789abcdef";
        string result = "";

        while(n>0)
        {
            int remainder = n % 16;
            result = hexChars[remainder] + result;
            n /= 16;
        }
        return result;
    }
};