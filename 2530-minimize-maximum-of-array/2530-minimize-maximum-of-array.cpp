class Solution {
public:
    bool isValid(vector<int>& nums,int expected_max,int n)
    {
        vector<long long> arr(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]>expected_max)
                return false;
            
            long long buffer = expected_max-arr[i];
            arr[i+1]=arr[i+1]-buffer;
        }
        return arr[n-1] <= expected_max;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int maxL = 0;
        int maxR = *max_element(nums.begin(),nums.end());

        int result;
        while(maxL <= maxR)
        {
            int mid_max = maxL + (maxR-maxL)/2;
            
            if(isValid(nums,mid_max,n))
            {
                result = mid_max;
                maxR = mid_max-1;
            }
            else
                maxL = mid_max+1;
        }
        return result;
    }
};