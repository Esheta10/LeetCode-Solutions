class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();

        int total = 0;

        for(int num: cardPoints)
            total += num;

        int window_size = n-k;

        if(window_size == 0)
            return total;

        int left = 0, right = 0;
        int window_sum = 0, min_window = INT_MAX;

        while(right < n){

            window_sum += cardPoints[right];

            // window fully formed
            if(right - left + 1 == window_size){
                min_window = min(min_window, window_sum);
                window_sum -= cardPoints[left];
                left++; 
            }
            right++;
        }
        return total - min_window;
    }
};