class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        int result=INT_MIN;
        for(int i=0;i<=n-2;i++)
        {
            int zero_count=0;
            //0 to i -> zero-count
            for(int j=0;j<=i;j++)
            {
                if(s[j]=='0')
                    zero_count++;
            }
            //i+1 to n-1 ->one's count
            int ones_count=0;
            for(int j=i+1;j<=n-1;j++)
            {
                if(s[j]=='1')
                    ones_count++;
            }
           result = max(result, zero_count+ones_count);
        } 
        return result;
    }
};