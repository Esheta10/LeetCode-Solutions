class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        
        int total = 0,digit_sum = 0;
        for(int num: nums){
            total += num;

            int temp = num;
            while(temp > 0){
            int rem = temp % 10;
            digit_sum += rem;
            temp = temp/10;
         }
        }

        return abs(total - digit_sum);
    }
};