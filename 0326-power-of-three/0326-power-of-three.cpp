//Approach-2 (simply dividing and checking recursively)
//T.C : O(log3(n))
//S.C : O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) {
            return false;
        }
        else if(n == 1) {
            return true;
        }
        return n%3 == 0 && isPowerOfThree(n/3);  
    }
};


  