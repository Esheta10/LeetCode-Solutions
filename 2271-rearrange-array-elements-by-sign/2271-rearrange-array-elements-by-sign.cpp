class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> result(n);
        int pos=0,neg=1;

        for(int num: nums)
        {
            if(num>0)
            {
                result[pos] = num;
                pos += 2;
            }
            else
            {
                result[neg] = num;
                neg += 2;
            }
        }
        return result;
    }
};