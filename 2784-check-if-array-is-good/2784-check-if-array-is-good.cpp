class Solution {
public:
    bool isGood(vector<int>& nums) {
        
        int n = nums.size();
        int max_ele = *max_element(nums.begin(),nums.end());

        if(nums.size() != max_ele + 1)
            return false;

        vector<int> freq(n,0);

        for(int i=0; i<n; i++){

            freq[nums[i]]++; 
            
            if(nums[i] != max_ele && freq[nums[i]] > 1)
                return false;
            if(nums[i] == max_ele && freq[nums[i]] > 2)
                return false;
        }
        return true;
    }
};