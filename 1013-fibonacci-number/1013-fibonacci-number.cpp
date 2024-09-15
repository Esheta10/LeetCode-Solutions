class Solution {
public:
    int fib(int n) {
        const int MOD=1e9+7;
        if(n==0) return 0;
        long long a=0,b=1;
        long long temp=0;
        for(int i=2;i<=n;i++)
        {
            temp=(a+b)%MOD;
            a=b;
            b=temp;
        }
        return b;
    }
};