class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;  // start and end blocked hai

        vector<pair<int,int>> directions = {
            {-1,-1} , {-1,0} , {-1,1} ,
            {0,-1},             {0,1},
            {1,-1}, {1,0}, {1,1}
        };

        // queue banao
        queue<vector<int>> q;
        q.push({0,0,1}); // {row, col, distance}
        grid[0][0] = 1; // mark visited

        while(!q.empty()){

            vector<int> current = q.front();
            q.pop();
            
            int row = current[0];
            int col = current[1];
            int dist = current[2];

            if(row == n-1 && col == n-1)
                return dist; // mil gaya

            // neighbors explore karo
            for(auto &direction : directions){
                int newRow = row + direction.first;
                int newCol = col + direction.second;


                if(newRow >= 0 && newRow < n &&
                  newCol >=0 && newCol < n &&
                  grid[newRow][newCol] == 0){
                    q.push({newRow, newCol, dist+1});
                    grid[newRow][newCol] = 1;
                  }
            }
            
        }
        return -1; // no path found
    }
};