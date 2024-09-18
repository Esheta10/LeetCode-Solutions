class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        /*APPROACH-1 
        int count=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]==nums[j])
                    count++;
            }
        }
        return count;   */
        /*APPROACH-2*/
        int n=nums.size();
        int result=0;
        unordered_map<int,int> mp;
        for(int &num:nums)//nums mein traverse karke map ko update kar rahe
            mp[num]++;

        for(auto &it:mp)//map mein traverse karke pair f/o kar rahe
        {
            int count=it.second;
            result += count*(count-1)/2;
        }
        return result;
    }
};