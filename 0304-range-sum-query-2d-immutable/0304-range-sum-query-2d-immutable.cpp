class NumMatrix {
public:
    vector<vector<int>> prefix;
    int rows, cols;
    NumMatrix(vector<vector<int>>& matrix) {
        
        rows = matrix.size();
        cols = matrix[0].size();

        // same size ka prefix matrix
        prefix.resize(rows, vector<int>(cols, 0));

        // prefix sum calculate karo
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                prefix[i][j] = matrix[i][j]; // current element

                if(i>0)
                    prefix[i][j] += prefix[i-1][j]; // upar ka sum add
                if(j>0)
                    prefix[i][j] += prefix[i][j-1]; // left ka sum add
                if(i>0 && j>0)
                    prefix[i][j] -= prefix[i-1][j-1];   // overlap minus
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int total = prefix[row2][col2]; // bada rectangle

        if(row1>0)
            total -= prefix[row1-1][col2]; // top subtract
        if(col1>0)
            total -= prefix[row2][col1-1]; // left subtract
        if(row1>0 && col1>0)
            total += prefix[row1-1][col1-1]; //overlap add block

        return total;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */