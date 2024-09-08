class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int n=nums.size();
       int insertPos=0;
       for(int j=0;j<n;j++)
       {
            if(nums[j]!=0)
            {
                nums[insertPos]=nums[j];
                insertPos++;
            }
       }
       for(int i=insertPos;i<n;i++)
            nums[i]=0;    
    }
};