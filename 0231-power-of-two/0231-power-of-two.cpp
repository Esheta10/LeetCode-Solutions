class Solution {
public:
    bool isPowerOfTwo(int n) {
        /*approach-1if(n<=0)
            return false;

        return (n&(n-1))==0;    */
       /*approach-2 if(n<=0)
            return false;
        int count=__builtin_popcount(n);
        return count==1;*/
        if(n==0)
            return false;
        if(n==1)
            return true;
        return n%2==0 && isPowerOfTwo(n/2);
    }
};