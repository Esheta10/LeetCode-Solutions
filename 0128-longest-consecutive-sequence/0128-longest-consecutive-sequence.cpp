class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();

        unordered_set<int> st(nums.begin(), nums.end());

        int longestStreak = 0;
        for(int num: st){
            // previous num nahi hai toh current element se streak banao
            if(st.find(num-1) == st.end()){
            
                int currentNum = num;
                int currentStreak = 1;
                
                while(st.find(currentNum + 1) != st.end()){
                    // next num after currentNum available hai toh increase the streak
                        currentNum++;
                        currentStreak++;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};