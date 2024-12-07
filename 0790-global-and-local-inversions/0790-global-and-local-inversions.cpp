class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            // Check if the current element is displaced by more than one position
            if (abs(nums[i] - i) > 1) {
                return false;
            }
        }
        return true;
    }
};