class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        
        int m = mat.size(); // row
        int n = mat[0].size();  // columns

        int maxCount = 0;
        int maxRow = 0;

        // check each row
        for(int i=0; i<m; i++){

            int count = 0;
            // count 1's in each row
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1)
                    count++;
            }

            // update if this row has more 1's
            if(count > maxCount){
                maxCount = count;
                maxRow = i;
            }
        }
        return {maxRow, maxCount}; // Return vector with [row_index, max_count]
    }
};