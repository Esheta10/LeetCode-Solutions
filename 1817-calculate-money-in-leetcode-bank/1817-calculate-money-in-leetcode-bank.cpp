//Approach-1 (Simple simulation)
//T.C : O(1) - see the video above to know why
//S.C : O(1)
class Solution {
public:
    int totalMoney(int n) {
        int result = 0;

        int monday_money = 1; //1dollar

        while(n > 0) {

            int money = monday_money; //1
            for(int day = 1; day <= min(n, 7); day++) {
                result += money;
                money++;
            }

            n -= 7;
            monday_money++;
        }

        return result;
    }
};