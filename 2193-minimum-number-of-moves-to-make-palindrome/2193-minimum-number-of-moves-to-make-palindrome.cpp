class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        
        int n = s.length();
        int swaps = 0;

        string str = s;

        int left = 0;
        int right = n-1;

        while(left < right){
            // characters already match
            if(str[left] == str[right]){
                left++;
                right--;
                continue;
            }

            // find matching character for str[left] from right side
            int k = right;
            while(k>left && str[k] != str[left])
                k--;

            // no match found, this is the odd frequency character
            if(k == left){
                swap(str[left], str[left+1]);
                swaps++;
                continue; // don't increment left, retry with swapped string
            }

            // match found at position k
            while(k < right){
                swap(str[k], str[k+1]);
                k++;
                swaps++;
            }
            left++;
            right--;
        }
        return swaps;
    }
};