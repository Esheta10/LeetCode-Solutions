class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {

        unordered_set<int> st(banned.begin(), banned.end());

        int count = 0;
        int sum = 0;

        for(int i=1; i<=n; i++){ // since the range is from 1

            if(st.find(i) != st.end())
                continue; // aage badh jao, 

            if(sum + i > maxSum)
                break;

            sum += i;
            count++;
        }   
        return count;
    }
};