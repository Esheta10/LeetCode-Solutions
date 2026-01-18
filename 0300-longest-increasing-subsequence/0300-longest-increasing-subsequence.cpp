class Solution {
public:
    int n;
    int t[2501][2501];
    int lis(vector<int>& nums, int i, int p){

        if(i >= n)
            return 0;

        if(p != -1 &&  t[i][p] != -1)
            return t[i][p];
        int take = 0;
        if(p == -1 || nums[i] > nums[p])
            take = 1 + lis(nums, i+1, i);

        int skip = lis(nums, i+1, p);

        if(p != -1)
            t[i][p] = max(take,skip);

        return max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        
        n = nums.size();
        memset(t, -1, sizeof(t));

        return lis(nums,0, -1);

    }
};