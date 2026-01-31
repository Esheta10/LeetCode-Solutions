class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int rows = mat.size();
        int cols = mat[0].size();

        int left = 0;
        int right = cols-1;

        while(left <= right){

            int midCol = left + (right - left)/2;
            
            int maxRow = 0;
            for(int row=0; row < rows; row++){
                if(mat[row][midCol] > mat[maxRow][midCol])
                    maxRow = row;
            }

            // check left neighbour
            int leftVal = (midCol > 0) ? mat[maxRow][midCol-1] : -1;
            // check right neighbour
            int rightVal = (midCol < cols-1) ? mat[maxRow][midCol+1] : -1;
            // current element
            int currVal = mat[maxRow][midCol];

            if(currVal > leftVal && currVal > rightVal)
                return {maxRow, midCol};
            else if(leftVal > currVal)
                right = midCol - 1;
            else
                left = midCol + 1;
        }
        return {-1,-1};
    }
};