class Solution {
public:
    string removeKdigits(string num, int k) {
        
        vector<char> st;

        for(char digit : num){

            while(!st.empty() && k>0 && st.back() > digit){
                st.pop_back();
                k--;
            }

            st.push_back(digit);
        }

        // trim remaining k from end
        while(k-- > 0){
            st.pop_back();
        }

        string result = "";
        bool leadingZeros = true;

        for(char c: st)
        {
            if(leadingZeros && c == '0')
                continue;

            leadingZeros = false;
            result += c;
        }
        return result.empty() ? "0" : result;
    }
};