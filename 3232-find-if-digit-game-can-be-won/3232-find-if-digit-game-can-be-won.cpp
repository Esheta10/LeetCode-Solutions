class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        
        int single_sum=  0;
        int double_sum = 0;

        int n = nums.size();

        for(int i=0; i<n; i++){

            if(nums[i] <= 9)
                single_sum += nums[i];
            else
                double_sum += nums[i];
        }

        if(single_sum < double_sum || single_sum > double_sum)
            return true;
        else
            return false;

    }
};