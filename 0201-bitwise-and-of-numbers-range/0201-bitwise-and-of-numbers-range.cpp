class Solution {
public:
//Approach-1 (Using shift)
//T.C : O(log(n)), where n is the maximum number of bits needed to represent the given input integers left and right.
//S.C : O(1)
    int rangeBitwiseAnd(int left, int right) {
      /*  int shiftCount=0;
        while(left!=right)
        {
          left = left >> 1;
          right = right >> 1;
          shiftCount++;
        }
        return left << shiftCount;*/
        while(right>left)
        {
            right = right & (right-1);
        }
        return right;
    }
};