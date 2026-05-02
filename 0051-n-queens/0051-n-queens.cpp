class Solution {
public:
    int N;
    vector<vector<string>> result;
    bool isValidBoard(vector<string>& board, int row, int col){

        // look upwards
        for(int i=row; i>=0; i--){
            if(board[i][col] == 'Q')
                return false;
        }

        // Check left diagonal upwards
        for(int i=row, j=col; i>=0 && j>=0; i--, j--){

            if(board[i][j] == 'Q')
                return false;
        }

        // Check right diagonal upwards
        for(int i=row, j=col; i>=0 && j<board.size(); i--,j++){

            if(board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void backtrack(vector<string> &board, int row){

        if(row == N){
            result.push_back(board);
            return;
        }

        for(int i=0; i<board.size(); i++){

            if(isValidBoard(board, row, i)){

                board[row][i] = 'Q'; // CHOOSE
                backtrack(board, row+1); // RECURSE
                board[row][i] = '.'; // UN-CHOOSE
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        N = n;

        vector<string> board(n, string(n, '.')); // for n = 3, board = {"...", "...", "..."}

        backtrack(board, 0);

        return result;

    }
};