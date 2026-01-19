class Solution {
public:
    int t[1001][1001];
    int LIS(string &s1, string &s2, int i, int j){

        if(t[i][j] != -1)
            return t[i][j];

        if(i >= s1.length() || j >= s2.length())
            return t[i][j] =  0;

        if(s1[i] == s2[j])
            return t[i][j] = 1 + LIS(s1, s2, i+1, j+1);
        else
            return t[i][j] = max(LIS(s1,s2,i+1,j), LIS(s1,s2,i,j+1));

    }
    int longestCommonSubsequence(string text1, string text2) {

        memset(t, -1, sizeof(t));
        return LIS(text1, text2, 0, 0);
    }
};