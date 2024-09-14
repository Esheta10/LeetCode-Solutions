class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       /*approach-1 for(int i=0;i<nums.size();i++)
        {
            nums[i]=nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;*/
        int n=nums.size();
        int i=0,j=n-1,k=n-1;
        vector<int> result(n);
        while(k>=0)
        {
            int a = nums[i]*nums[i];
            int b=nums[j]*nums[j];
            if(a>b)
            {
                result[k]=a;
                i++;
            }
            else
            {
                result[k]=b;
                j--;
            }
            k--;          
        }
        return result;
    }
};