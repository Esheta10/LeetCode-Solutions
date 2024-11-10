class Solution {
public:
    void computeLPS(string pattern, vector<int> &lps) {
        int N = pattern.length();
        int len = 0; // length of the previous longest prefix and suffix
        lps[0] = 0; // no proper prefix and suffix for the first character
        int i = 1;
        
        while (i < N) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0)
                    len = lps[len - 1];
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    vector<int> KMP(string pattern, string txt) {
        int N = txt.length();
        int M = pattern.length();
        vector<int> result;
        vector<int> lps(M, 0);

        // Preprocess pattern to fill lps array
        computeLPS(pattern, lps);

        int i = 0; // index for txt
        int j = 0; // index for pattern
        
        while (i < N) {
            if (txt[i] == pattern[j]) {
                i++;
                j++;
            }
            if (j == M) { // found pattern at index (i - j)
                result.push_back(i - j);
                j = lps[j - 1];
            } else if (i < N && txt[i] != pattern[j]) {
                if (j > 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return result;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.length();
        vector<int> i_indices = KMP(a, s);
        vector<int> j_indices = KMP(b, s);

        vector<int> result;

        for (int &i : i_indices) {
            int left_limit = max(0, i - k);
            int right_limit = min(n - 1, i + k);

            // Find first index `j` in `j_indices` that is >= left_limit
            auto it = lower_bound(j_indices.begin(), j_indices.end(), left_limit);

            // Check if this `j` is within the allowed range [left_limit, right_limit]
            if (it != j_indices.end() && *it <= right_limit) {
                result.push_back(i);
            }
        }
        return result;
    }
};
