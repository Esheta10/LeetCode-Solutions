class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);

        vector<vector<int>> dp(n+2,vector<int>(n+2,0));

        for(int len=2;len<n+2;len++)
        {
            for(int i=0;i<n+2-len;i++)
            {
                int j = i+len;
                for(int k=i+1; k<j;k++)
                {
                    dp[i][j] = max(dp[i][j], nums[i]*nums[j]*nums[k] + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][n+1];
    }
};