class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();

        // search from top-right corner
        int row = 0;
        int col = cols-1;

        while(row < rows && col >= 0){

            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] > target)  // current value is too large, move left
                col--;
            else    // current value is too small, move down
                row++;
        }
        return false;
    }
};