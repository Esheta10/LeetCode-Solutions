class Solution {
public:
    int tribonacci(int n) {
     if(n==0)
            return 0;
        int a=0;
        int b=1;
        int c=1;
        int temp=0;
        for(int i=3;i<=n;i++)
        {
            temp = a+b+c;
            a=b;
            b=c;
            c=temp;
        }
        return c;
       
    }
};