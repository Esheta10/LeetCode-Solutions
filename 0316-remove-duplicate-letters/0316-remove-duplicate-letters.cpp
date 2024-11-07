class Solution {
public:
    string removeDuplicateLetters(string s) {
       int n = s.length();
       stack<char> st;

       vector<bool> taken(26,false);// Keeps track of characters already in the stack
       vector<int> lastIndex(26,0);// Stores the last index of each character in the string
       // Step 1: Record the last occurrence index for each character
       for(int i=0;i<n;i++)
       {
            lastIndex[s[i]-'a']=i;
       }
       // Step 2: Process each character in the string
       for(int i=0;i<n;i++)
       {
            char currentChar = s[i];
            int index = currentChar - 'a';
             // If character is already in stack, skip it
            if (taken[index])
                continue;
            // Remove characters from stack that:
            // - Are lexicographically larger than the current character
            // - Appear later in the string (we can re-add them after the current character)
            while(!st.empty() && st.top()>currentChar && lastIndex[st.top()-'a']>i)
            {
                taken[st.top()-'a']=false;// Mark removed character as "not taken"
                st.pop();
            }
            // Push current character onto the stack and mark it as "taken"
            st.push(currentChar);
            taken[index]=true;
       }
     // Step 3: Build result string from stack
       string result;
       while(!st.empty())
       {
            result.push_back(st.top());
            st.pop();
       }
       reverse(result.begin(),result.end());// Reverse to get correct order
       return result;
    }
};