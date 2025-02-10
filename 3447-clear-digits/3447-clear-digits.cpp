class Solution {
public:
    string clearDigits(string s) {
     stack<char> st;

        for(char &ch : s) {
            if(ch >= 'a' && ch <= 'z') {
                st.push(ch);
            } else if(!st.empty()) {
                st.pop();
            }
        }

        string result = "";
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(begin(result), end(result));

        return result;
    }
};