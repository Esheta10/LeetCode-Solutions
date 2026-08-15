class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<char> st;

        for(char &ch: num){

            while(!st.empty() && k>0 && st.top() > ch){
                st.pop();
                k--;
            }
            
            st.push(ch);
        }


        // agar num string already ascending order mein ho like - 12345, then remove last k digits directly
        while(k>0){
            st.pop();
            k--;
        }


        // for leading zeros -> 10200, k=1
        // output is -> 0200 but we must ignore leading 0 and only return 200 as output
        string numArray = "";
        // stack se elements nikal kar string mein daalna
        while(!st.empty()){
            numArray += st.top();
            st.pop();
        }
        // qki stack se lements ulte order mein extract hoga
        reverse(numArray.begin(), numArray.end());

        string result = "";
        bool leadingZeros = true;

        for(char &c : numArray){

            if(leadingZeros && c == '0')
                continue; // skip this iteration

            leadingZeros = false;
            result += c;
        }
        return result.empty() ? "0" : result; // "22" , k=2 mein output 0 hoga 
    }
};