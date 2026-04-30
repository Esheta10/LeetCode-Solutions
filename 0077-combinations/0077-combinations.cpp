class Solution {
public:
    vector<vector<int>> result;
    void backtrack(int start, int &n, int k, vector<int>& temp){

        if(k == 0){
            result.push_back(temp);
            return;
        }

        if(start > n)
            return;

        temp.push_back(start); // CHOOSE
        backtrack(start+1, n, k-1, temp); // RECURSE

        temp.pop_back(); // UN-CHOOSE
        backtrack(start+1, n, k, temp);
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> temp;

       backtrack(1, n, k, temp);

       return result;
    }
};