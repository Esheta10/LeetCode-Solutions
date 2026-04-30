class Solution {
public:
    int m;
    int ans = INT_MIN;
    void backtrack(int idx, int count, vector<int>& result, vector<vector<int>>& requests){

        if(idx == m){
            
            bool allZero = true;
            for(int &num : result){
                if(num != 0){
                    allZero = false;
                    break;
                }
            }
            if(allZero){
                ans = max(ans, count);
            }

            return;
        }

        int from = requests[idx][0];
        int to = requests[idx][1];

        result[from]--;
        result[to]++;
        backtrack(idx+1, count+1, result, requests);

        result[from]++;
        result[to]--;
        backtrack(idx+1, count, result, requests);

    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        
        m = requests.size();

        // n -> buildings
        vector<int> result(n, 0);

        backtrack(0, 0, result, requests);

        return ans;
    }
};