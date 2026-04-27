class Solution {
public:
    int m, n;
    bool isWordPresent(vector<vector<char>>& board, int i, int j, string& word, int idx){


        if(idx == word.length()) // agar word ke saare characters mil gaye
            return true;

        // boundary conditions and character mis-match check
        if(i<0 || j<0 || i>=m || j>=n || board[i][j] != word[idx])
            return false;

        bool ans = false;

        // Temporarily, mark the cell as visited
        char temp = board[i][j];
        board[i][j] = '$';

        // check all possible directions (up, down, left, right)
        ans = ans | isWordPresent(board, i-1, j, word, idx+1);
        ans = ans | isWordPresent(board, i+1, j, word, idx+1);
        ans = ans | isWordPresent(board, i, j-1, word, idx+1);
        ans = ans | isWordPresent(board, i, j+1, word, idx+1);

        // Restore the original character in cell
        board[i][j] = temp;

        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        m = board.size();
        n = board[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                // If the first character of board matches the starting character of word, check for other characters of word as well
                if(board[i][j] == word[0]){

                    if(isWordPresent(board, i,j, word, 0))
                        return true;
                }
            }
        }
        // If the word is not found, return false
        return false;
    }
};