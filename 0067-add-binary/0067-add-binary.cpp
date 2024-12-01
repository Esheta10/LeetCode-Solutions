class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;
        
        // Process the strings from the rightmost bit to the leftmost bit
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) carry += a[i--] - '0';  // Add bit from string a
            if (j >= 0) carry += b[j--] - '0';  // Add bit from string b
            
            result.push_back(carry % 2 + '0');  // Add the result of this bit to the result string
            carry /= 2;  // Update carry for the next iteration
        }
        
        // The result is built in reverse, so reverse it before returning
        reverse(result.begin(), result.end());
        
        return result;
    }
};