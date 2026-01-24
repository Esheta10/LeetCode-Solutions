class Solution {
public:
    typedef long long ll;
    vector<vector<int>> result;
    void twoSum(vector<int>& nums, ll remaining, int i, int j, int n1, int n2){

        while(i<j){
            ll sum = (ll)nums[i] + (ll)nums[j];
            if(sum < remaining)
                i++;
            else if(sum > remaining)
                j--;
            else{
                while(i<j && nums[i]==nums[i+1]) i++;
                while(i<j && nums[j]==nums[j-1]) j--;
                result.push_back({n1,n2, nums[i], nums[j]});
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        if(n < 4)
            return {};
        
        result.clear();

        //1. sort the elements
        sort(nums.begin(), nums.end());

        //2. fix two elements - n1 & n2
        for(int i=0; i<n; i++){

            if(i>0 && nums[i]==nums[i-1])// skip duplicates
                continue;

            for(int j=i+1; j<n; j++){

                if(j>i+1 && nums[j]==nums[j-1]) // skip duplicates
                    continue;

                // n1+n2+n3+n4 = target
                // n3+n4 = target - n1 - n2;
                // remaining = target - n1 - n2;
                ll remaining = (ll)target - (ll)nums[i] - (ll)nums[j];
                twoSum(nums, remaining, j+1, n-1, nums[i], nums[j]);
            }
        }
        return result;
    }
};