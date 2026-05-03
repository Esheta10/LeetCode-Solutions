class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& result, int idx){

        if(target < 0)
            return;

        if(target == 0){
            result.push_back(temp);
            return;
        }

        for(int i=idx; i<candidates.size(); i++){

            if(i>idx && candidates[i] == candidates[i-1])
                continue;

            temp.push_back(candidates[i]);  // CHOOSE
            backtrack(candidates,target - candidates[i], temp, result, i+1);    // RECURSE
            temp.pop_back();    // UN-CHOOSE
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        
        vector<int> temp;
        vector<vector<int>> result;

        backtrack(candidates, target, temp, result, 0);

        return result;
    }
};