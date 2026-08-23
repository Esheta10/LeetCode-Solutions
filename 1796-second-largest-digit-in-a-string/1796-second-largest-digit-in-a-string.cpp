class Solution {
public:
    int secondHighest(string s) {
        
       int max = -1;
       int second_max = -1;

       for(char c: s){

            if(isdigit(c)){
                int num = c - '0';
            

                if(num > max){
                    second_max = max;
                    max = num;
                }
                else if(num > second_max && num < max){
                    second_max = num;
                }

            }
       }
       return second_max;
    }
};