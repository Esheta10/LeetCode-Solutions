class Solution {
public:
    int n;
    vector<vector<int>> result;
    void backtrack(int i, vector<int>& nums, vector<int>& temp){

        if(i == nums.size()){
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);    // CHOOSE
        backtrack(i+1, nums, temp); // RECURSE
        temp.pop_back();    // UN-CHOOSE
        backtrack(i+1, nums, temp);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        n = nums.size();
        vector<int> temp;

        backtrack(0, nums, temp);

        return result;
    }
};