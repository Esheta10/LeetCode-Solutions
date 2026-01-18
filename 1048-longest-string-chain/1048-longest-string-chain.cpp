class Solution {
public:
    int n;
    int t[1001][1001];
    bool predecessor(string &prev, string& curr){

        int M = prev.length();
        int N = curr.length();

        if(M >= N || N-M != 1)
            return false;

        int i=0, j=0;
        while(i<M && j<N){
            if(prev[i] == curr[j])
                i++;

            j++;
        }

        return i==M;
    }
    int lis(vector<string>& words, int i, int p){

        if(i >= n)
            return 0;
        
        if(p != -1 && t[i][p] != -1)
            return t[i][p];

        int take=0;
        if(p == -1 || predecessor(words[p], words[i]))
            take = 1 + lis(words, i+1, i);

        int skip = lis(words, i+1, p);

        if(p != -1)
            t[i][p] = max(take, skip);

        return max(take, skip);
    }
    static bool myFunction(string &s1, string &s2){
        return s1.length() < s2.length();
    }
    int longestStrChain(vector<string>& words) {
        
        n = words.size();
        sort(words.begin(), words.end(),myFunction);

        memset(t, -1, sizeof(t));

        return lis(words, 0, -1);
    }
};