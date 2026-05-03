class Solution {
public:
    void backtrack(int k, int n, vector<int>& temp, vector<vector<int>> &result, int idx){
        
        if(temp.size() == k && n==0){
            result.push_back(temp);
            return;
        }

        if(temp.size() == k || n<=0)
            return; // prune

        for(int i=idx; i<=9; i++){

            temp.push_back(i);
            backtrack(k, n-i, temp, result, i+1);
            temp.pop_back();

        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        // k -> numbers.size()
        // n --> target
        vector<int> temp;

        vector<vector<int>> result;

        backtrack(k, n, temp, result, 1);

        return result;
    }
};