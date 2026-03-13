class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        
        long long sum = 0;
        long long ans = 0; 

        int n = nums.size();


        for(int i=0; i<n; i++){

            sum += nums[i];
            long long count = i+1;

            long long minMax = ceil((1.0 * sum)/ count);

            ans = max(ans, minMax);
        }
        return ans;
    }
};