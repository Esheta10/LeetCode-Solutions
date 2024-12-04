class Solution {
public:
    int countPrimeSetBits(int left, int right) {
         // Precompute prime numbers up to 20 (maximum number of set bits for numbers ≤ 10^6)
        unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
        
        int count = 0;

        for (int num = left; num <= right; ++num) {
            // Count the number of set bits in the binary representation of `num`
            int setBits = __builtin_popcount(num); // GCC/Clang built-in function
            
            // Check if the count of set bits is prime
            if (primes.count(setBits)) {
                ++count;
            }
        }
        
        return count;
    }
};