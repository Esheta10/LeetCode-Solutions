class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int current_streak = 0;
        int best_streak = 0;

        for(int num: nums){
            
            if(num == 1){
                current_streak++;
                best_streak = max(current_streak, best_streak);
            } else{
                current_streak = 0;
            }
        }
        return best_streak;
    }
};