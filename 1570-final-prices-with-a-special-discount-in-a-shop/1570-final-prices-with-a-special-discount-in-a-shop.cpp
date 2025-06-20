class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        //Approach-1 (Brute Force)
        //T.C : O(n^2)
        //S.C : O(1)
        /*
        int n = prices.size();

        //vector<int> result(prices.begin(),prices.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(prices[i] >= prices[j])
                {
                    prices[i] -= prices[j];
                    break;
                }
            }
        }
        return prices;*/
        
        int n = prices.size();
        vector<int> result(prices.begin(),prices.end());

        stack<int> st;

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && prices[i] <= prices[st.top()])
            {
                result[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};