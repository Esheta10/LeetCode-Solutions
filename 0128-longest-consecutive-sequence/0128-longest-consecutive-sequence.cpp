class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.empty())
            return 0;

        int longestStreak = 0;

        unordered_set<int> st(nums.begin(), nums.end());

        for(int num : st){

            if(st.find(num-1) == st.end()){
                // currentNum ka previous value set pe nahi hai so start from here
                int currentNum = num;
                int currentStreak = 1;

                while(st.find(currentNum + 1) != st.end()){
                        currentNum++;
                        currentStreak++;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};