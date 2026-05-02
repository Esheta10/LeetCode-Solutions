class Solution {
public:
    int Sum(vector<int>& candidates){

        int sum = 0;
        for(int num: candidates){
            sum += num;
        }
        return sum;
    }
    void backtrack(vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>> &result, int idx){

        if(idx >= candidates.size() || Sum(temp) > target)
            return;

        if(Sum(temp) == target){
            result.push_back(temp);
            return;
        }

        temp.push_back(candidates[idx]);    // CHOOSE
        backtrack(candidates, target, temp, result, idx);   // RECURSE

        temp.pop_back();    // UN-CHOOSE
        backtrack(candidates, target, temp, result, idx+1); //RECURSE
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> temp;

        vector<vector<int>> result;

        backtrack(candidates, target, temp, result, 0);

        return result;
    }
};