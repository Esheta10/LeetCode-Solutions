class Solution {
public:
    bool isPowerOfTwo(int n) {
        /*approach-1if(n<=0)
            return false;

        return (n&(n-1))==0;    */
        if(n<=0)
            return false;
        int count=__builtin_popcount(n);
        return count==1;
    }
};