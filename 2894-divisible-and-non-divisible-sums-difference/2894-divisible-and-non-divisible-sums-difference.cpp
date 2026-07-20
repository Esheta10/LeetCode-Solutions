class Solution {
public:
    int differenceOfSums(int n, int m) {
        
        int difference = 0;
        for(int i=1; i<=n; i++){

            if(i%m == 0){
                difference -= i;
            } else {
                difference += i;
            }
        }
        return difference;
    }
};