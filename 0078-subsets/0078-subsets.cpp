class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int>& nums,int i,vector<int>& temp)
    {
        if(i>=nums.size())
        {
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);    //take
        solve(nums,i+1,temp);   //trust
        temp.pop_back();    //not-take
        solve(nums,i+1,temp);   //trust
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        
        solve(nums,0,temp);

        return result;
    }
};