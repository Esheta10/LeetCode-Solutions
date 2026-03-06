class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        int n = nums.size();
        vector<string> result;
        int i = 0;

        while(i<n){

            int start = i;

            // keep going while consecutive
            while(i+1<n && nums[i+1] == nums[i]+1)
                i++;

            //single number
            if(start == i)
                result.push_back(to_string(nums[start]));
            else
                result.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));


            i++;
        }
        return result;
    }
};