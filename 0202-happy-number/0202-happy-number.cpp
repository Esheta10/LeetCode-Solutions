class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int> st;

        while(st.find(n) == st.end()){

            st.insert(n);
            n = getNextNumber(n);

            if(n == 1)
                return true;
        }

        return false;
    }

    int getNextNumber(int n){

        int result = 0;
        while(n > 0){

            int digit = n % 10;
            result += digit * digit;
            n /= 10;
        }
        return result;
    }

};