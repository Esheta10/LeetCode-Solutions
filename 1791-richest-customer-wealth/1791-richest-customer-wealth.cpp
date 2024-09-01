class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth=0;// Initialize maximum wealth to 0
        for(const auto& customer:accounts)
        {
            // Calculate the sum of the current customer's accounts
            int currentWealth=accumulate(customer.begin(),customer.end(),0);

            // Update maximum wealth if the current wealth is greater
            maxWealth=max(currentWealth,maxWealth);
        }
        return maxWealth;
    }
};