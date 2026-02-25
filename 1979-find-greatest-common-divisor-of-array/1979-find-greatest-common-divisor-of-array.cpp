class Solution {
public:
    int gcd(int a, int b){

        if(b==0)
            return a;
        else
            return gcd(b, a%b);
        
    }
    int findGCD(vector<int>& nums) {
        
        int minValue = *min_element(nums.begin(),nums.end());
        int maxValue = *max_element(nums.begin(), nums.end());

        return gcd(minValue, maxValue);
    }
};