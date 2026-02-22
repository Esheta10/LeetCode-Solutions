class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();

        int XorArr = 0, XorAll = 0;

        for(int i=0; i<=n; i++){
            XorAll ^= i;
        }

        for(int num : nums){
            XorArr ^= num;
        }

        return XorAll ^ XorArr;
    }
};