class Solution {
public:
    int n;
    vector<vector<int>> result;
    void backtrack(int idx, vector<int>& temp, vector<int>& nums){

      
        result.push_back(temp);
        
        unordered_set<int> st;

        for(int i = idx; i<n; i++){

            if(st.find(nums[i]) != st.end())
                continue;

            temp.push_back(nums[i]);    // CHOOSE
            st.insert(nums[i]);

            backtrack(i+1, temp, nums); // RECURSE

            temp.pop_back();   // UN-CHOOSE
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int> temp;

        backtrack(0, temp, nums);

        return result;
    }
};