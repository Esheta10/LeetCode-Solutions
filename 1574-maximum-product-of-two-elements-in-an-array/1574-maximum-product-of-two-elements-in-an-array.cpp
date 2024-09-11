class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*APPROACH-1
        int n=nums.size();
        int curr_max=nums[0];
        int result=0;
        for(int i=1;i<n;i++)
        {
            result=max(result,(nums[i]-1)*(curr_max-1));
            curr_max=max(curr_max,nums[i]);
        }
        return result;*/
        int largest=0;
        int s_largest=0;
        for(int &num:nums)
        {
            if(num>largest)
            {
                s_largest=largest;
                largest=num;
            }
            else
            {
                s_largest=max(s_largest,num);
            }
        }
        return (largest-1)*(s_largest-1);
    }
};