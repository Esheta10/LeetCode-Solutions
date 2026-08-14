class Solution {
public:
    string removeKdigits(string num, int k) {
        
        vector<char> st;

        for(char digit : num){

            while(!st.empty() && k>0 && st.back() > digit){
                st.pop_back(); // remove larger element
                k--;
            }

            st.push_back(digit);
        }

        // trim remaining k from end --> agar number ascending ordr mein ho and k exist karta ho
        while(k> 0){
            st.pop_back();
            k--;
        }

        // build result, skip leading zeros
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