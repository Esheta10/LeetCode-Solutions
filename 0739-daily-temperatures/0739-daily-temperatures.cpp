class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        stack<int> st; // we are pushing indices into the stack, as that will help us in determining 
        // difference in tempeartues
        vector<int> result(n);

        for(int i=n-1; i>=0; i--){

            while(!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();

            result[i] = st.empty() ? 0 : st.top() - i;

            st.push(i); // push the current index into the stack
        }
        return result;
    }
};