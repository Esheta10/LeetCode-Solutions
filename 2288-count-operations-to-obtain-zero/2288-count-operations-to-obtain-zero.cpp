//Approach-1 (Using Maths similar to Euclidean Algorithm - Iterative)
//T.C : O(log(min(a, b)))
//S.C : O(1)
class Solution {
public:
    int countOperations(int num1, int num2) {
        int count = 0;

        while(num1 > 0 && num2 > 0) {
            count += num1/num2;

            num1 %= num2;

            swap(num1, num2);
        }

        return count;
    }
};