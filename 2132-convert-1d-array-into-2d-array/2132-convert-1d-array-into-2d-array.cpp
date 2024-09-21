class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        vector<vector<int>> result(m,vector<int>(n));
        int l=original.size();

        if(l != m*n)
        {
            return {};
        }
        int idx=0;
        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                result[row][col]=original[idx];
                idx++;
            }
        }
        return result; 
    }
};