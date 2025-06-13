class Solution {
public:
    int minOperations(vector<string>& logs) {
        //Approach-1:
        //T.C.=O(n)
        //S.C.=O(1)
        int depth=0;
        for(string &log:logs)
        {
            if(log=="../")
                depth=max(0,depth-1);
            else if(log=="./")
                continue;
            else
                depth++;
        }
        return depth;
        //Approach-2 (Using Stack for simulation)
        //T.C : O(n)
        //S.C : O(n)
        stack<string> st;
        for(string &log:logs)
        {
            if(log=="../")
            {
                if(!st.empty())
                    st.pop();
            }
            else if(log=="./")
                continue;
            else
                st.push(log);
        }
        return st.size();
    }
};