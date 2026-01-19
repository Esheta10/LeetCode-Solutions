class Solution {
public:
    int n;
    int t[1001][201];
    int solve(int idx, vector<int>& nums, int target){

        if(target == 0)
            return 1;
        
        if(idx >= n || target < 0)
            return 0;

        if(t[target][idx] != -1)
            return t[target][idx];
            
        int take = solve(0, nums, target-nums[idx]);
        int skip = solve(idx+1, nums,target);

        return  t[target][idx] = take + skip;
    }
    int combinationSum4(vector<int>& nums, int target) {
        
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(0, nums, target);

    }
};