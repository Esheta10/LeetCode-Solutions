class Solution {
public:
    int m,n;
    int result;
    int nonObstacles;
    
    vector<vector<int>> directions = {{-1,0}, {1,0} , {0,-1}, {0, 1}};
    void backtrack(vector<vector<int>>& grid, int i, int j, int count){

        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == -1)
            return;

        if(grid[i][j] == 2){

            if(count == nonObstacles)
                result++;

            return;
        }  

        grid[i][j] = -1; // visited element

        // Backtracking logic
        // if(i-1>=0 && grid[i-1][j] != -1) backtrack(grid, i-1, j, count+1); // UP
        // if(i+1<m && grid[i+1][j] != -1) backtrack(grid, i+1, j, count+1); // DOWN
        // if(j-1>=0 && grid[i][j-1] != -1) backtrack(grid, i, j-1, count+1); // LEFT
        // if(j+1<n && grid[i][j+1] != -1) backtrack(grid, i, j+1, count+1); // RIGHT

        for(vector<int> dir : directions){

            int new_i = i + dir[0];
            int new_j = j + dir[1];
            backtrack(grid, new_i, new_j, count+1);
        }

        grid[i][j] = 0; // set the values back to 0 while backtracking and finding another possible path

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid[0].size();

        result = 0;
        nonObstacles = 0;

        int start_x = 0, start_y = 0;

        for(int i=0; i<m; i++){

            for(int j=0; j<n; j++){

                if(grid[i][j] == 0)
                    nonObstacles++; // count the no. of non-obstacles

                if(grid[i][j] == 1){ // starting point
                    start_x = i;
                    start_y = j;
                }
            }
        }

        nonObstacles += 1; // sinces we have both 0's and the initial starting point - 1 as non-obstacles

        int count = 0;

        backtrack(grid, start_x, start_y, count);

        return result;
    }
};