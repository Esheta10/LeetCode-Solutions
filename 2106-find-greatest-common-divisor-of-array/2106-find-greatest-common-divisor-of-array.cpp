class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest=*min_element(nums.begin(),nums.end());
        int largest=*max_element(nums.begin(),nums.end());

        return gcd(smallest,largest);
    }
    private:
        int gcd(int a,int b)
        {
            while(b!=0)
            {
                int temp=b;
                b=a%b;
                a=temp;
            }
            return a;
        }
};