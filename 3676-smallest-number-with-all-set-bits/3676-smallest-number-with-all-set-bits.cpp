//Approach-1 (Simple looping till we get result)
//T.C : O(result - n), where result = (next power of 2 > n) - 1
//S.C : O(1)
class Solution {
public:
    bool isAllBitsSet(int x) {
        return (x & (x+1)) == 0;
    }
    int smallestNumber(int n) {
        int result = n;

        while(!isAllBitsSet(result)) {
            result++;
        }

        return result;
    }
};

