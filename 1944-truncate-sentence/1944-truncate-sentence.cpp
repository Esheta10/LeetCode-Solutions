class Solution {
public:
    string truncateSentence(string s, int k) {
        stringstream ss(s);
        string token="";
        string result="";
        int count=0;
        while(ss >> token)
        {
            if(count>=k)
                break;
            if(count>0)
                result += " ";
                
            result += token;
            count++;
        }
        return result;

    }
};