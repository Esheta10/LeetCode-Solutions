class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        int dir=0;
        int top=0, down=m-1;
        int left=0,right=n-1;

        vector<int> res;

        while(top<=down && left<=right){
            if(dir==0){
                //left -> right
                for(int i=left;i<=right;i++){
                    res.push_back(matrix[top][i]);
                }
                top++;
            }
            if(dir==1){
                for(int i=top;i<=down;i++){
                // top -> down
                    res.push_back(matrix[i][right]);
                }
                right--;
            }
            if(dir==2){
                for(int i=right;i>=left;i--){
                // right -> left
                res.push_back(matrix[down][i]);
                }
                down--;
            }
            if(dir==3){
                for(int i=down;i>=top;i--){
                // down -> top
                res.push_back(matrix[i][left]);
                }
                left++;
            }

            dir = (dir + 1)% 4;
        }
        return res;
    }
};