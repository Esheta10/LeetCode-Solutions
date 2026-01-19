class Solution {
public:
    int solve(int m, int n, int i,int j, vector<vector<int>>& t){

        if(i==m-1 && j==n-1)
            return 1;

        if(i<0 || i>=m || j<0 || j>=n)
            return 0;

        if(t[i][j] != -1)
            return t[i][j];

        int right = solve(m, n, i, j+1, t);
        int down = solve(m, n, i+1, j, t);

        return t[i][j] = right + down;
    }
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> t(m+1, vector<int>(n+1,-1));

        return solve(m,n,0,0,t);
    }
};