class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        for(int &bill : bills)
        {
            if(bill==5)
                five++;
            else if(bill==10)//return $5
            {
                if(five>0)
                {
                    five--;
                    ten++;
                }
                else
                    return false;
            }
            else if(five > 0 && ten >0)//return $5,$5,$5 or $10,$5 for $20 bill
            {
                five--;
                ten--;
            }
            else if(five>=3)
                five -= 3;//return $5,$5,$5
            else
                return false;
        }
        return true;
    }
};