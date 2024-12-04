class Solution {
public:
    int hammingDistance(int x, int y) {
        int xor_result = x^y;
        int hamming_distance=0;
        while(xor_result)
        {
            hamming_distance += xor_result & 1;
            xor_result >>= 1;
        }
        return hamming_distance;
    }
};