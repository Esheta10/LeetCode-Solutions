class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> rowRes;
        for(int row=0;row<m;row++)
        {
            int rowMin=INT_MAX;
            for(int col=0;col<n;col++)
            {
                rowMin=min(rowMin,matrix[row][col]);
            }
            rowRes.push_back(rowMin);
        }
        vector<int> colRes;
        for(int col=0;col<n;col++)
        {
            int colMax=INT_MIN;
            for(int row=0;row<m;row++)
            {
                colMax=max(colMax,matrix[row][col]);
            }
            colRes.push_back(colMax);
        }
        vector<int> result;
        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(matrix[row][col]==rowRes[row] && matrix[row][col]==colRes[col])
                    result.push_back(matrix[row][col]);
            }
        }
        return result;
    }
};