class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
        sort(capacity.begin(), capacity.end(), greater<int>()); // in descending order

        int totalApples = accumulate(apple.begin(), apple.end(),0);


        int count = 0; // boxes used
        int i=0;

        while(totalApples > 0){

            totalApples -= capacity[i];
            count++;
            i++;
        }
        return count;
    }
};