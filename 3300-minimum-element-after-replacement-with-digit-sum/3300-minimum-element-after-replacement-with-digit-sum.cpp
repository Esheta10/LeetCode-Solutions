class Solution {
public:
    int digitSum(int n){

        int sum = 0;

        while(n>0){

            int rem = n%10;
            sum = sum + rem;
            n /= 10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        
        int result = 37;

        for(int num: nums){

            int curr_num_digit_sum  = digitSum(num);
            result = min(result, curr_num_digit_sum);
        }
        return result;
    }
};