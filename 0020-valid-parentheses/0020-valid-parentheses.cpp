class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char ch:s)
        {
           if (ch == '(' || ch == '{' || ch == '[') {
            // Push opening brackets onto the stack
            stk.push(ch);
        } else {
            // If the stack is empty, we have a closing bracket without an opening
            if (stk.empty()) return false;
            
            // Check if the closing bracket matches the opening bracket on top of the stack
            if ((ch == ')' && stk.top() == '(') ||
                (ch == '}' && stk.top() == '{') ||
                (ch == ']' && stk.top() == '[')) {
                stk.pop(); // Pop the matched opening bracket
            } else {
                // Mismatched closing bracket
                return false;
            }

         }
     }
      // If the stack is empty, all brackets were matched
    return stk.empty();
    }
};