class Solution {
public:
    vector<vector<int>> result;
    void twoSum(vector<int>& nums, long long  newTarget, int i, int j, int first,int second){
        while(i<j){
            if( nums[i] + nums[j] <  newTarget)
                i++;
            else if( nums[i] + nums[j] > newTarget)
                j--;
            else{
                while(i<j && nums[i]==nums[i+1]) i++;
                while(i<j && nums[j]==nums[j-1]) j--;

                result.push_back({first,second,nums[i],nums[j]});
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        if(n<4)
            return {};
        
        result.clear();
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){

            if(i>0 && nums[i]==nums[i-1])   
                continue;

            for(int j=i+1;j<n;j++){

                if(j>i+1 && nums[j]==nums[j-1])
                    continue;

                long long  first = nums[i];
                long long  second = nums[j];

                long long newTarget = (long long)target - first - second;

                twoSum(nums,newTarget,j+1,n-1,first,second);
            }
        }
        return result;
    }
};