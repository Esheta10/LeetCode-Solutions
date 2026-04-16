class Solution {
public:
    typedef long long ll;
    long long subArrayRanges(vector<int>& nums) {
        
        int n = nums.size();
        ll sum = 0;

        for(int i=0; i<n; i++){

            int minVal = nums[i];
            int maxVal = nums[i];

            for(int j=i+1; j<n; j++){

                minVal = min(minVal, nums[j]);
                maxVal = max(maxVal, nums[j]);

                sum += maxVal - minVal;
            }
        }
        return sum;
    }       
};