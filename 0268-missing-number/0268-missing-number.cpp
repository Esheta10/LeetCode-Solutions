class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int missing = 0;

        vector<int> freq(n+1,0);

        for(int num : nums)
            freq[num]++;

        for(int i=0; i<=n; i++){

            if(freq[i] == 0)
                missing = i;
        }
        return missing;
    }
};