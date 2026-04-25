class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector<int> result(n);

        stack<pair<int,int>> st;

        for(int i=n-1; i>=0; i--){
            
            int span = 1;
            while(!st.empty() && st.top().first <= temperatures[i]){
                    span += st.top().second;
                    st.pop();
            }
            result[i] = st.empty() ? 0 : span;

            st.push({temperatures[i], span});
        }
        return result;
    }
};