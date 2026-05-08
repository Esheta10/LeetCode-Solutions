class Solution {
public:
    int result;
    int K;
    void backtrack(int idx, vector<int>& nums, unordered_map<int, int> &mp){

        if(idx >= nums.size()){
            result++;
            return;
        }

        // not-take
        backtrack(idx+1, nums, mp);

        // take
        if(!mp[nums[idx] - K] && !mp[nums[idx] + K]){ // nahi mila

            mp[nums[idx]]++; // choose
            backtrack(idx+1, nums, mp);
            mp[nums[idx]]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        
        result = 0;
        K = k;

        unordered_map<int, int> mp;

        backtrack(0, nums, mp);
        return result-1;
    }
};