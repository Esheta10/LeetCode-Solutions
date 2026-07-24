class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;

        for(char ch: s){

            if(ch == '(' || ch == '[' || ch == '{')
                st.push(ch);
            else{

                if(st.empty())
                    return false; // agar closing bracket hai aur stack empty hai, toh invalid case

                char top = st.top();

                if(ch == ')' && top != '(')
                    return false;
                if(ch == '}' && top != '{')
                    return false;
                if(ch == ']' && top != '[')
                    return false;

                st.pop();
            }
        }
        return st.empty();
    }
};