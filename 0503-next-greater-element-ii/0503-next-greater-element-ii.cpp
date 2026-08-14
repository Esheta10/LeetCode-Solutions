class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(2*n);
        stack<int> st;

        for(int i = 2*n-1; i>=0; i--){
            

            // pop karo elements jo current se chote ya barabar ho
            while(!st.empty() && st.top() <= nums[i%n])
                st.pop();

            ans[i] = st.empty() ? -1 : st.top();
            st.push(nums[i%n]);
        }
        // End mein sirf pehle n elements ko extract karke return kar diya
        return vector<int>(ans.begin(), ans.begin() + n);
    }
};