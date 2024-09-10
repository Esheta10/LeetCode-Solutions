class Solution {
public:
    vector<vector<int>> result;
    void twoSum(vector<int>& nums,int target,int i,int j)
    {
        while(i<j)
        {
            int sum=nums[i]+nums[j];
            if(sum>target)j--;
            else if(sum<target)i++;
            else
            {
                //sum==target-->first we'll remove duplicates from either end (i,j)
                while(i<j && nums[i]==nums[i+1])i++;
                while(i<j && nums[j]==nums[j-1])j--;
                result.push_back({-target,nums[i],nums[j]});
                i++;
                j--;

            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return {};
        result.clear();
        //sort
        sort(nums.begin(),nums.end());
        //fixing one element n1
        for(int i=0;i<=n-3;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int n1=nums[i];
            int target=-n1;
            twoSum(nums,target,i+1,n-1);//it will find n1,n2 & n3 : {n1,n2,n3}
        }
        return result;
    }
};