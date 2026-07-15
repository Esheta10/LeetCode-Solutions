class Solution {
public:
    int xorOperation(int n, int start) {
        
        int output = 0;
        while(n--){
            output ^= start;
            start +=2;
        }
        return output;
    }
};