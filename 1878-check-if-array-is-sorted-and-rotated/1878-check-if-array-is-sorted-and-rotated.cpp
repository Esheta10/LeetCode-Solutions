class Solution {
public:
    bool check(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> temp(nums);

        for(int r=0;r<n;r++)
        {
            rotate(temp.begin(),temp.begin()+r,temp.end());

            bool isSorted = true;
            for(int i=0;i<n-1;i++)
            {
                if(temp[i]>temp[i+1])
                {
                    isSorted = false;
                    break;
                }
            }
            if(isSorted)
                return true;

            temp = nums;//reset for next iteration
        }
        return false;
    }
};