class Solution {
public:
    int sumOfDivisors(int num)
    {
        set<int> divisors;
        for(int i=1;i*i<=num;i++)
        {
            if(num%i==0)
            {
                 divisors.insert(i);
                 divisors.insert(num/i);
            }
        }
        if(divisors.size()==4)
        {
            int sum=0;
            for(int d:divisors)
            {
                sum+=d;
            }
            return sum;
        }
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int totalSum=0;
        for(int num:nums)
        {
            totalSum+=sumOfDivisors(num);
        }
        return totalSum;
    }
};