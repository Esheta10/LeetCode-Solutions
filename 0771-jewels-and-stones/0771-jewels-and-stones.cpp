class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        unordered_set<int> st(jewels.begin(), jewels.end());

        int count = 0;
        for(char &stone : stones){
            if(st.find(stone) != st.end())
                count++;
        }
        return count;
    }
};