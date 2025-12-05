class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        // Approach - 1
        // int n = digits.size();

        // int carry = 1;

        // for(int i=n-1;i>=0;i--){
        //     int sum = digits[i] + carry;

        //     digits[i] = sum % 10;
        //     carry = sum / 10;
        // }
        // if(carry)
        //     digits.insert(digits.begin(),1);

        // return digits;

        // Approach-2 

        int n = digits.size();

        for(int i=n-1;i>=0;i--){

            if(digits[i] < 9){
            // agar digit 9 se choti ho toh directly 1 add karke return kar do
                digits[i]++;
                return digits;
            }
            digits[i]=0;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};