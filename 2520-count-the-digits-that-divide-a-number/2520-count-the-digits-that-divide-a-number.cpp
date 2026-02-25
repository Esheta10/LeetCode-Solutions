class Solution {
public:
    int countDigits(int num) {
        
        int temp = num;
        int count = 0;

        while(num > 0){

            int lastDigit = num%10;
            if(lastDigit != 0 && temp % lastDigit==0)
                count++;
            num = num/10;
        }
        return count;
    }
};