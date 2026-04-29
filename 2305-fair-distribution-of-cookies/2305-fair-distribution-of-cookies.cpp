class Solution {
public:
    int n;
    int result = INT_MAX;
    void backtrack(int idx, vector<int>& cookies, vector<int>& children, int k){

        if(idx == cookies.size()){

            int ans = *max_element(children.begin(), children.end());
            result = min(result, ans);
            return;
        }

        int candy = cookies[idx];
        for(int i=0; i<k; i++){

            children[i] += candy;
            backtrack(idx+1, cookies, children, k);
            children[i] -= candy;
        }

    }
    int distributeCookies(vector<int>& cookies, int k) {
        
        n = cookies.size();
        vector<int> children(k);
        backtrack(0, cookies, children, k);

        return result;
    }
};