class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min_price=INT_MAX;
        int s_min_price=INT_MAX;
        for(int &price:prices)
        {
            if(price<min_price)
            {
                s_min_price=min_price;
                min_price=price;
            }
            else
            {
                s_min_price=min(s_min_price,price);
            }
        }
        if((min_price+s_min_price)>money)
            return money;
        
        return money-(min_price+s_min_price);
    }
};