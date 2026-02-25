class Solution {
public:
    int countDigits(int num) {
        
        int originalNum = num;
        int count = 0;

        while(num > 0){

            int lastDigit = num%10;
            if(lastDigit != 0 && originalNum % lastDigit==0)
                count++;
            num = num/10;
        }
        return count;
    }
};