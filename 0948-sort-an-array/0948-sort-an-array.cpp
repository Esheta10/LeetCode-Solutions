class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int minE= *min_element(nums.begin(),nums.end());
        int maxE= *max_element(nums.begin(),nums.end());

        unordered_map<int,int> mp;

        for(int &num:nums)
        {
            mp[num]++;
        }
        int i=0;
        for(int num=minE;num<=maxE;num++)
        {
            while(mp[num]>0)
            {
                nums[i]=num;
                i++;
                mp[num]--;
            }
        }
       return nums;
    }
};