class Solution {
public:
    string buildString(string &s)
    {
        int n=s.length();
        int i=0;
        string temp = "";
        while(i<n)
        {
            if(s[i]!='#')
                temp.push_back(s[i]);
            else if(!temp.empty())
                temp.pop_back();

            i++;
        }
        return temp;
    }
    bool backspaceCompare(string s, string t) {
        return buildString(s)==buildString(t);
    }
};