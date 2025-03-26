class Solution {
public:
    int numberOfMatches(int n) {
    /* APPROACH-1
       return (n-1);    */
       int matches=0;
       while(n>1)
       {
            if(n%2==0)//even
            {
                matches += n/2;
                n=n/2;
            }
            if(n%2!=0)
            {
                matches += (n-1)/2;
                n=(n-1)/2 +1;
            }
       }
       return matches;
    }
};