class Solution {
public:
    //APPROACH-1
    /*
    int t[38];
    int find(const int &n)
    {
        if(n==0)
            return 0;
        if(n==1 || n==2)
            return 1;
        if(t[n]!=-1)
            return t[n];
        int a = find(n-1);
        int b = find(n-2);
        int c = find(n-3);

        return t[n]=a+b+c;
    }
    int tribonacci(int n) {
        memset(t,-1,sizeof(t));
        return find(n);
    */
    int tribonacci(int n) {
    if(n==0)
        return 0;
    if(n==1 || n==2)
        return 1;
    int a=0;
    int b=1;
    int c=1;
    int d=a+b+c;
    for(int i=3;i<=n;i++)
    {
        d=a+b+c;

        a=b;
        b=c;
        c=d;
    }
    return d;
    }
};